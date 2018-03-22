/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction for game logic
see the FBullCowGame class.*/

#include <iostream>
#include <string>
#include <ctype.h>
#include "FBullCowGame.h"

//Transforming into Unreal standards
using FText = std::string; //for Unreal user interaction
using int32 = int;

/*----------------------
Function prototype
----------------------*/

void PrintIntro();
void PlayGame();
FText GetValidGuess(int32);
bool AskToPlayAgain();

FBullCowGame BCGame; //make this instance global to our code

//The entry point for our application
int main() {	
	do {
		PrintIntro();
		PlayGame();		
	} while (AskToPlayAgain() == true);
	return 0;
}

/*----------------------
Functions
----------------------*/

//introduce the game
void PrintIntro() {		
	std::cout << "Welcome to Bulls and Cows\n\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n\n";
	return;
}
//main function for our BullsAndCows game
void PlayGame()
{
	BCGame.Reset(); //resets the game everytime this function runs
	int32 MaxTries = BCGame.GetMaxTries();
	//loop for the number of turns asking for guess	
	for (int32 count = 0; count < MaxTries; count++) {
		FText Guess = GetValidGuess(count);
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//user's output to check if its guess are close or not to our hidden word
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " | Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "Your guess was " << Guess << "\n\n";	
	}
}
//this will loop continually until the user gives a valid guess
FText GetValidGuess(int32 CurrentTry) {			
	EGuessStatus Status = EGuessStatus::Invalid_Status; //initializing our status so we can use as a condition for our do-while loop
	CurrentTry += BCGame.GetCurrentTry(); //this is to control what guess number is
	do {
		//get a guess from the player		
		FText Guess = "";
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		getline(std::cin, Guess); //this read all the line before press ENTER

		//this will check user's guess and if's not OK will return an error message showing what's wrong
		 Status = BCGame.CheckGuessValidity(Guess);
		//error messages
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n"; break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating any letters.\n"; break;
		default: //OK case
			return Guess; break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //will keep looping until user's guess are OK by our definitions
}
//self explanatory, LOL!
bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (yes/no): ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (tolower(Response[0]) == 'y'); //return with logical decision
}
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
FText GetValidGuess();
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
	int32 CurrentTry = BCGame.GetCurrentTry(); //initializing the Try number counter
	int32 MaxTries = BCGame.GetMaxTries();	
	//loop for the number of turns asking for guess	while the game is NOT won and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		std::cout << "Try " << CurrentTry << std::endl;
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		//user's output to check if its guess are close or not to our hidden word
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " | Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "Your guess was " << Guess << "\n\n";
		CurrentTry++; //if we reach this part, the guess will be valid and we can increase our counter
		
	}
}
//this will loop continually until the user gives a valid guess
FText GetValidGuess() {			
	EGuessStatus Status = EGuessStatus::Invalid_Status; //initializing our status so we can use as a condition for our do-while loop	
	 //get a guess from the player	
	FText Guess = "";	
	do {
		std::cout << "Enter your guess: ";
		getline(std::cin, Guess); //this read all the line before press ENTER
		//this will check user's guess and if's not OK will return an error message showing what's wrong
		Status = BCGame.CheckGuessValidity(Guess);
		//error messages
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n"; break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating any letters.\n"; break;
		default:
			Status = EGuessStatus::OK; break;		
		}		
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); //will keep looping until user's guess are OK by our definitions
	return Guess; //we will only return Guess if our Status = OK so it will leave the do-while loop
}
//self explanatory, LOL!
bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (yes/no): ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (tolower(Response[0]) == 'y'); //return with logical decision
}
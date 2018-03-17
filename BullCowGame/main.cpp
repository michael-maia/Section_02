/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction for game logic
see the FBullCowGame class.*/

#include <iostream>
#include <string>
#include <ctype.h>
#include "FBullCowGame.h"

//Transforming into Unreal standards
using FText = std::string; //FText => for user interaction
using int32 = int;

//Function prototypes
void PrintIntro();
void PlayGame();
void GetGuess(int32);
bool AskToPlayAgain();

FBullCowGame BCGame;

//The entry point for our application
int main() {	
	do {
		BCGame.Reset();
		PrintIntro();
		PlayGame();		
	} while (AskToPlayAgain() == true);
	return 0;
}

//Functions
void PrintIntro() {	
	//introduce the game
	constexpr int32 WORD_LENGTH = 9; //constant variable
	std::cout << "Welcome to Bulls and Cows\n" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}
void GetGuess(int32 CurrentTry) {
	//get a guess from the player	
	CurrentTry += BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess); //read all the line before you press ENTER
	std::cout << "Your guess was " << Guess << std::endl; //and print the guess back	
}
void PlayGame()
{	
	int32 MaxTries = BCGame.GetMaxTries();	
	//loop for the number of turns asking for guess	
	for (int32 i = 0; i < MaxTries; i++) {
		GetGuess(i);
		std::cout << std::endl;
	}
}
bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (yes/no): ";
	FText Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (tolower(Response[0]) == 'y'); //return with logical decision
}
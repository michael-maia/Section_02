#include <iostream>
#include <string>
#include <ctype.h>
#include "FBullCowGame.h"

//Function Prototype
void PrintIntro();
void PlayGame();
void GetGuess(int);
bool AskToPlayAgain();

FBullCowGame BCGame;

//The entry point for our application
int main() {
	do {
		PrintIntro();
		PlayGame();		
	} while (AskToPlayAgain() == true);
	return 0;
}

//Functions
void PrintIntro() {	
	//Introduce the game
	constexpr int WORLD_LENGTH = 9; //Constant variable
	std::cout << "Welcome to Bulls and Cows\n" << std::endl;
	std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}
void GetGuess(int CurrentTry) {
	//Get a guess from the player	
	CurrentTry += BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	getline(std::cin, Guess); //Read all the line before you press ENTER
	std::cout << "Your guess was " << Guess << std::endl; //And print the guess back	
}
void PlayGame()
{	
	int MaxTries = BCGame.GetMaxTries();	
	//Loop for the number of turns asking for guess	
	for (int i = 0; i < MaxTries; i++) {
		GetGuess(i);
		std::cout << std::endl;
	}
}
bool AskToPlayAgain() {
	std::cout << "Do you want to play again? (yes/no): ";
	std::string Response = "";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (tolower(Response[0]) == 'y'); //Return with logical decision
}
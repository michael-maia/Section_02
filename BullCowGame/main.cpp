#include <iostream>
#include <string>

//Function Prototype
void PrintIntro();
void PlayGame();
void GetGuessAndPrintBack();

//The entry point for our application
int main() {
	PrintIntro();	
	PlayGame();
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

void GetGuessAndPrintBack() {
	//Get a guess from the player
	std::string Guess = "";
	std::cout << "What's your guess: ";
	getline(std::cin, Guess); //Read all the line before you press ENTER
	std::cout << "Your guess was " << Guess << std::endl; //And print the guess back	
}

void PlayGame()
{
	//Loop for the number of turns asking for guess
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++) {
		GetGuessAndPrintBack();
		std::cout << std::endl;
	}
}
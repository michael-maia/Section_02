#pragma once //This makes the file to be imported only one time
#include <string>


class FBullCowGame {
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram;
};


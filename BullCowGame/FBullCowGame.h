#pragma once //This makes the file to be imported only one time
#include <string>


class FBullCowGame {
public:	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(std::string);

private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram;
};


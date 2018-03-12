#pragma once //This makes the file to be imported only one time

class FBullCowGame {
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity();

private:
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram();
};


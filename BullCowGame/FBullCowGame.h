#pragma once //This makes the file to be imported only one time
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:		
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString); //TODO with more details

private:
	//Check constructor for inicialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram;
};


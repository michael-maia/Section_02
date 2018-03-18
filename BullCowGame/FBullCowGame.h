#pragma once //This makes the file to be imported only one time
#include <string>

using FString = std::string;
using int32 = int;

struct BullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:		
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	void Reset();
	bool CheckGuessValidity(FString); //TODO with more details	
	BullCowCount SubmitGuess(FString);

private:
	//Check constructor for inicialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram;
	FString MyHiddenWord;
};


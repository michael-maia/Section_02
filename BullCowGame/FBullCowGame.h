#pragma once //This makes the file to be imported only one time
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	OK,
	Not_Isogram,
	Wrong_Length	
};

class FBullCowGame {
public:		
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; //TODO with more details
	void Reset();		
	FBullCowCount SubmitGuess(FString);

private:
	//Check constructor for inicialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
	bool IsIsogram;
	FString MyHiddenWord;
};


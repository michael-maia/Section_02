#include "FBullCowGame.h"

//Constructor
FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset(){
	MyCurrentTry = 1;
	constexpr int32 MAX_TRIES = 8;
	const FString HIDEN_WORD = "planet";
	MyHiddenWord = HIDEN_WORD; 
	MyMaxTries = MAX_TRIES;
	return; 
}
bool FBullCowGame::IsGameWon() const {
	return false;
}
bool FBullCowGame::CheckGuessValidity(FString){
	return false;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	MyCurrentTry++;
	BullCowCount BullCowCount;
	return BullCowCount;
}

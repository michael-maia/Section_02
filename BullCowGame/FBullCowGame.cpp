#include "FBullCowGame.h"

//Constructor
FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset(){
	MyCurrentTry = 1;
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD; 
	MyMaxTries = MAX_TRIES;
	return; 
}
bool FBullCowGame::IsGameWon() const {
	return false;
}
bool FBullCowGame::CheckGuessValidity(FString){
	return false;
}
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{	
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for(int32 i = 0; i < HiddenWordLength; i++) {
		for (int32 j = 0; j < HiddenWordLength; j++) {
			if (tolower(Guess[i]) == MyHiddenWord[j]) { //comparing the guess against our hidden word
				if (i == j) { //if the letters are in the same place
					BullCowCount.Bulls++;
				}
				else { //if is not
					BullCowCount.Cows++;
				}
			}

		}
	}
	return BullCowCount;
}

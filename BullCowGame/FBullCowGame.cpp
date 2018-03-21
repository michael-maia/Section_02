#include "FBullCowGame.h"

//Constructor
FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset(){	
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD; 
	MyMaxTries = MAX_TRIES;
	return; 
}
bool FBullCowGame::IsGameWon() const {
	return false;
}
bool FBullCowGame::CheckGuessValidity(FString) const{
	return false;
}
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{	//MHChar = My Hidden Word Character | GChar = Guess Char
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) {
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) {
			if ((Guess[GChar]) == MyHiddenWord[MHWChar]) { //comparing the guess against our hidden word
				if (MHWChar == GChar) { //if the letters are in the same place
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

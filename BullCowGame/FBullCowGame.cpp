#include "FBullCowGame.h"

/*----------------------
Constructor
----------------------*/

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

//this will reset the game
void FBullCowGame::Reset(){	
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";	
	MyHiddenWord = HIDDEN_WORD; 
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return; 
}
bool FBullCowGame::IsGameWon() const {
	return false;
}
//user's output to check if its guess are close or not to our hidden word
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const{
	if (false) {
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}
//checking how many Bulls and Cows the user did
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{	
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	for(int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) { //MHChar = My Hidden Word Character
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) { //GChar = Guess Char
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

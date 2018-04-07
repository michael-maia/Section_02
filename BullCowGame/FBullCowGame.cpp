#include "FBullCowGame.h"

/*----------------------
Constructor
----------------------*/

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

//this will reset the game
void FBullCowGame::Reset(){	
	constexpr int32 MAX_TRIES = 2;
	const FString HIDDEN_WORD = "planet";	
	MyHiddenWord = HIDDEN_WORD; 
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	bIsGameWon = false;
	return; 
}
//the game can only be beatable if bulls are equal to the number of letters in our hidden word
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
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{		
	FBullCowCount BullCowCount;		
	int32 WordLength = MyHiddenWord.length(); //assuming same length as guess
	for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) { //MHChar = My Hidden Word Character
		for (int32 GChar = 0; GChar < WordLength; GChar++) { //GChar = Guess Char
			//comparing the guess against our hidden word
			if ((Guess[GChar]) == MyHiddenWord[MHWChar]) { 
				if (MHWChar == GChar) { //if the letters are in the same place
					BullCowCount.Bulls++;
				}
				else { //if is not
					BullCowCount.Cows++;
				}
			}
		}
	}	
	if (BullCowCount.Bulls == GetHiddenWordLength()) {
		bIsGameWon = true;
	}
	else {
		bIsGameWon = false;
	}
	MyCurrentTry++; //if the player's guess is valid, the try counter will increase
	return BullCowCount;
}

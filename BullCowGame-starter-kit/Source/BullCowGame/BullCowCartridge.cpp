// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{ 
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }

    else
    {    
        ProcessGuess(Input);
    }
}
    
void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len(); 
    bGameOver = false;
    
    PrintLine(TEXT("Welcome To BullCow Game!"));
    PrintLine(TEXT("Guess word of length:%i"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives for this round"), Lives); 
    PrintLine(TEXT("Press Enter to continue"));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if(Guess == HiddenWord)
    {
        PrintLine(TEXT("You Guessed The Word Correctly!"));
        EndGame();    
        return;
    }

    if(Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("You lost a life! Lives Remaining: %i"), Lives);
        PrintLine(TEXT("Hidden Word is %i characters long!"), HiddenWord.Len());  
        return;
    }

    --Lives;
    if(Lives == 0)
    {
        PrintLine(TEXT("You have lost all lives"));
        EndGame();
        return;
    }

    else
    {
        PrintLine(TEXT("You have %i lives remaining"), Lives);
        PrintLine(TEXT("Wrong Guess!"));
    }
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    ClearScreen();
    PrintLine(TEXT("Press Enter to continue"));
}
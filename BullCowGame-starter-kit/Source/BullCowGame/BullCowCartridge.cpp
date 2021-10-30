// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    PrintLine(TEXT("This is a Bull Cows Game!"));
    PrintLine(TEXT("Guess the 6 letter word")); // TODO: Remove magic number
    PrintLine(TEXT("Let's try to find out the word..."));

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You have guessed correctly"));

        // Play again?
        // Yes: Reset game
        // No: Quit game
    }
    else
    {
        PrintLine(TEXT("Your guess is incorrect"));
        
        // Subtract a life

        // Are there remaining lives?
        // No: You lose, print lost message, ask if play again

        // Is the word length correct?
        // No: Remind the word length

        // Is word an isogram?
        // No: you need to give an isogram

        // Calculate hints based on Input 
        // and give feedback to player
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("number");
    Lives = 4;
}
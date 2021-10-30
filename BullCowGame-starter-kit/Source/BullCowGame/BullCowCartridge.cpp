// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("[DEBUG]  The hidden word is: %s"), *HiddenWord);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("You have guessed correctly"));
            EndGame();

            // Play again?
            // Yes: Reset game
            // No: Quit game
        }
        else
        {
            if (HiddenWord.Len() != Input.Len())
            {
                PrintLine(TEXT("The length of the word is incorrect\nLength should be %i"), HiddenWord.Len());
                EndGame();
            }
        
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

    // if the game is over, then do something
    // else check the player guess

}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cakes");
    Lives = 4;
    bGameOver = false;

    PrintLine(TEXT("This is a Bull Cows Game!"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len()); // TODO: Remove magic number
    PrintLine(TEXT("Let's try to find out the word..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game is over\nPress ENTER to play again..."));
}
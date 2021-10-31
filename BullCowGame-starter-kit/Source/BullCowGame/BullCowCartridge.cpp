// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordList/HiddenWordList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);

    SetupGame();

    PrintLine(TEXT("Number of valid words: %i"), GetValidWords(Words).Num());
    PrintLine(TEXT("[DEBUG]  The hidden word is: %s"), *HiddenWord);
    /*for (int32 i = 0; i < Words.Num(); ++i)
    {
        PrintLine(TEXT("[DEBUG] %s"), *Words[i]);
    }*/
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
        ProcessGuess(Input);
    }

    // if the game is over, then do something
    // else check the player guess

}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("This is a Bull Cows Game!"));
    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len()); // TODO: Remove magic number
    PrintLine(TEXT("Let's try to find out the word..."));
    PrintLine(TEXT("You have %i lives remaining"), Lives);

    const TCHAR HW[] = TEXT("cakes");
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Game is over\nPress ENTER to play again..."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    // TODO
    // Subtract a life

    // Are there remaining lives?
    // No: You lose, print lost message, ask if play again

    // Is the word length correct?
    // No: Remind the word length

    // Is word an isogram?
    // No: you need to give an isogram

    // Calculate hints based on Input 
    // and give feedback to player

    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have guessed correctly"));
        EndGame();
        return;
    }

    if (HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("The length of the word is incorrect\nLength should be %i"), HiddenWord.Len());
        return;
    }

    if (!IsIsogram(Guess))
    {
        PrintLine(TEXT("No repeating letters, guess again"));
        return;
    }

    PrintLine(TEXT("Word is not matching, life lost"));
    --Lives;
    
    if (Lives > 0)
    {
        PrintLine(TEXT("%i lives remaining"), Lives);
    }
    else
    {
        PrintLine(TEXT("You don't have more lives"));
        EndGame();
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for (int32 i = 0; i < Word.Len(); ++i)
    {
        for (int32 j = i + 1; j < Word.Len(); ++j)
        {
            if (Word[i] == Word[j])
            {
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word))
        {
            ValidWords.Emplace(Word);
        }
    }

    return ValidWords;
}
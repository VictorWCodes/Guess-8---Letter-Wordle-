# Guess-8---Letter-Wordle-
Guess the Word Game

Overview

This program is a word-guessing game where a random eight-letter word is selected from a predefined file. The player guesses letters one at a time, and if a guessed letter is present in the word, its position(s) will be revealed. The objective is to guess all the letters in the word with the fewest misses possible.

Features

Random Word Selection: Picks a word randomly from a file (words.txt).

Letter Guessing: Players can guess one letter at a time.

Miss Tracking: Keeps track of incorrect guesses.

Best Score Comparison: Notifies the player if they beat or matched the best score.

Replay Option: Players can choose to play again.

Usage Instructions

1. Compiling the Program

To compile guess.cpp, use the following command in a terminal:

 g++ guess.cpp -o guess

Ensure that words.txt is present in the same directory.

2. Running the Program

Execute the compiled program using:

 ./guess

3. Game Flow

The game will display a welcome message and randomly select a word.

The player will be prompted to guess a letter (a-z, lowercase only).

The program will indicate:

If the letter is correct, it will be revealed in the word.

If the letter is incorrect, a miss is recorded.

If the letter has been guessed before, a warning is displayed.

The game continues until the player completes the word.

The program will compare the score to the best score and display the results.

The player is asked whether they want to play again.

4. Example Gameplay

WELCOME! Guess the mystery word!
Word: -------- Missed: 0
Enter a lowercase letter (a to z): a
MISS! The letter a is not in the word.
Word: -------- Missed: 1
Enter a lowercase letter (a to z): e
The letter e is in the word.
...
You have completed the word!!!
The word is example
You had 3 misses.
You beat the best score!
Do you want to play again (y/n)?

Implementation Details

Random word selection is done using rand() seeded with time(0).

Words are loaded from words.txt, ensuring up to 1000 words can be stored.

Game logic checks guessed letters, updates the displayed word, and tracks misses.

Input validation ensures only lowercase letters are accepted.

The best score is stored and compared after each game session.

Dependencies

C++ Standard Library (iostream, fstream, cstdlib, ctime, cstring)

A text file (words.txt) containing a list of words.

Author

Victor Wong

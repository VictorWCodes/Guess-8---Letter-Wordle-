/* Guess.cpp
Purpose: A random eight-letter word is selected. The player will guess
letters in the word one at a time. If the letter is in the word,the 
location(s) will be revealed. It will be considered a miss. The goal of the
game is to guess of the letters in the word with as few misses as possible.
Input: There is input from the file. Then once the game starts the input is 
the users guesses which have to be lowercase letters. 
Output: The output of this program is the Welcome message intially which
briefly explains what the game is. Then after each guess it displays whether 
the guess is invalid and if the letter (guess) appears in the word. It also
lets the user know the amount of incorrect guesses. Then dispays whether the
user beat the best score or not. Lastly it ask the user if they would like to
play again.
*/
#include <iostream> 
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime> 

using namespace std; 
//Declaring Constants here
const int MAX_WORDS = 1000;
const int WORD_LENGTH = 8;
const string FILE_NAME = "words.txt";

//Function Protoypes
int readWordFile(string fileName, string wordList[]);
string pickMysteryWord(string wordList[], int numWords);
int playGame(string mystery);
char getGuess();
void compareBestScore(int totalScore, int &bestScore);

//Main Function
int main(){
    //Declares the array where the words from the file will be stored
    string wordList[MAX_WORDS];
    //Gets the number of words from the text file
    int numWords = readWordFile("words.txt", wordList);
    //Sets high score to something unrealistic
    int bestScore = 100;
    bool playAgain;

//Do while loop which plays the game so long it is true
    do{
        playAgain = true;
        //Organized Spacing 
        cout << endl;
        cout << "WELCOME! Guess the mystery word!" << endl;
        
        //Getting the mystery word here
        string mystery = pickMysteryWord(wordList, numWords);
        
        //The amount of misses from the playGame function
        int misses = playGame(mystery);
        
        //Compares the best scores if the user plays multiple games
        compareBestScore(misses, bestScore);
        
        //Asking the user if they want to play again
        char x;
        cout << "Do you want to play again (y/n)? "; 
        cin >> x;

        if (!(x == 'y')){
            playAgain = false;
        }

    } while (playAgain);

    return 0;
}

//Read words from input file and store them within array
int readWordFile(string fileName, string wordList[]){
    int numWords = 0;
//Opening the input file and reading the words into the wordList array
    ifstream inFile("words.txt"); 
    if(inFile.is_open()){
        while(numWords < MAX_WORDS && inFile >> wordList[numWords]){
        //Counting the number of words through each iteration
            numWords++;
        }
    }
//Error message if file doesn't open 
    else{
        cout << "Error opening file: " << fileName << endl; 
    }
//Returning the number of words from the file
    return numWords;
}

//Randomly select a word from the word list
string pickMysteryWord(string wordList[], int numWords){
//Seeding the random word chooser
    srand(time(0));
    int i;
    i = rand() % numWords; 
//Returning the Word List
    return wordList[i];
}

//Play Game function which allows the user to guess the mystery word
int playGame(string mystery){
//Displaying the unknown word
    string guessedWord = "";
    for(int i = 0; i < WORD_LENGTH; i++){
        guessedWord += '-';
    }
//Setting the amount of misses to 0
    int miss = 0;

/*While loop for when the word is not complete the game keeps prompting 
the user for a guess*/
    bool wordComplete = false; 

    while(!wordComplete){
//Displays the word along with the amount of misses the user has
        cout << "Word: " << guessedWord << " Missed: " << miss << endl;
//Gets the guess from the user
        char guess = getGuess();
        bool alreadyGuessed = false;
        for(int i= 0; i < WORD_LENGTH; i++){
            if(guessedWord[i] == guess)
            alreadyGuessed = true;
        }
//Displays a message if the user had already guessed that letter
        if(alreadyGuessed){
            miss++;
            cout << "You already guessed that letter!" << endl;
        }

        bool match = false;
        for (int i = 0; i < WORD_LENGTH; i++){
            if (mystery[i] == guess){
                guessedWord[i] = guess;
                match = true;
            }
        }
//Displaying the appropriate message according to user input
        if(!match){
            miss++;
            cout << "MISS! The letter " << guess 
            << " is not in the word." << endl;
        }
        else
        cout << "The letter " << guess << " is in the word. " << endl;

        if (guessedWord == mystery){
            wordComplete = true;
            cout << endl;
            cout << "You have completed the word!!!" << endl;
        }
        if (!wordComplete){
            cout << endl;
        }
    }
//End Message once the user has guessed the word
        cout << "The word is " << mystery << endl;
        cout << "You had " << miss << " misses." << endl;

    return miss;
}

//Gets a valid guess from the user
char getGuess(){
    char guess;
    bool validInput = false; 

    cout << "Enter a lowercase letter (a to z): ";
    cin >> guess;
//While loop to ensure user inputs only lowercase letters
    while(!validInput){
        if(!(islower(guess))){
            cout << "Invalid guess. Enter a lowercase letter (a to z): ";
            cin >> guess;
        }
        else{
            validInput = true; 
        }
    }
    return guess;
}

//Fucntion for comparing the best score
void compareBestScore(int totalScore, int &bestScore){
//Comparing and printing out the appropriate messages
    if (totalScore < bestScore){
        bestScore = totalScore;
        cout << "You beat the best score!" << endl; 
    }
    else if(totalScore == bestScore){
        cout << "You matched the best score!" << endl; 
    }
    else{
        cout << "Best score is: " << bestScore << endl; 
    }
}


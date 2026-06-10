#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <map>

using namespace std;
using namespace chrono;

vector<pair<string, string>> wordList;
map<string, int> leaderboard;

// Function prototypes
void loadWordsFromFile();
string getRandomWord(string &hint);
string scrambleWord(string word);
void playGame(int difficulty, string playerName);
void displayLeaderboard();

int main() {
    char playAgain;
    string playerName;

    // Load words and hints from file
    loadWordsFromFile();

  cout << "                                                  |--------------------------\n";
  cout << "                                                  |         WELCOME         |\n";
  cout << "                                                  |           TO            |\n";
  cout << "                                                  |      WORDS SCRAMBLE     |\n";
  cout << "                                                  |           GAME          |\n";
  cout << "                                                  --------------------------|\n";
  cout << "                                                   (\\__/) ||                \n";
  cout << "                                                   (> <)//                   \n";
  cout << "                                                   / ~|                      \n";
    cout << "\nRules of the Game:\n";
    cout << "1. A scrambled word will be shown on the screen.\n";
    cout << "2. You have a limited time to unscramble it.\n";
    cout << "3. You get 3 attempts to guess correctly.\n";
    cout << "4. You can use a hint, but it costs 5 points.\n";
    cout << "5. Points are awarded based on difficulty level:\n";
    cout << "   - Easy: 10 points\n";
    cout << "   - Medium: 20 points\n";
    cout << "   - Hard: 30 points\n";
    cout << "6. The leaderboard tracks the highest scores!\n\n";

    cout << "Enter your name: ";
    cin >> playerName;

    do {
        int difficulty;
        cout << "Choose difficulty (1 - Easy, 2 - Medium, 3 - Hard): ";
        cin >> difficulty;

        playGame(difficulty, playerName);

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
        cin.ignore();
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\n\n===== Leaderboard =====\n";
    displayLeaderboard();

cout << "                                                  |--------------------------\n";
  cout << "                                                  |         GOODBYE         |\n";
  cout << "                                                  |        THANK YOU        |\n";
  cout << "                                                  |      FOR BEING HERE     |\n";
  cout << "                                                  --------------------------|\n";
  cout << "                                                   (\\__/) ||                \n";
  cout << "                                                   (> <)//                   \n";
  cout << "                                                   / ~|                      \n";
    return 0;
}

// Function to load words and hints from file
void loadWordsFromFile() {
    ifstream file("words.txt"); // Ensure words.txt is in the same directory
    if (!file) {
        cerr << "Error: Could not open words.txt!\n";
        exit(1);
    }

    string word, hint;
    while (file >> word) {
        getline(file, hint); // Read hint after the word
        wordList.push_back({word, hint});
    }

    file.close();

    if (wordList.empty()) {
        cerr << "Error: No words loaded from file.\n";
        exit(1);
    }
}

// Function to get a random word and its hint
string getRandomWord(string &hint) {
    if (wordList.empty()) {
        cerr << "Error: No words available. Make sure words.txt is loaded correctly.\n";
        exit(1);
    }

    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> distr(0, wordList.size() - 1);
    int index = distr(gen);
    hint = wordList[index].second;
    return wordList[index].first;
}

// Function to scramble a word
string scrambleWord(string word) {
    random_device rd;
    mt19937 g(rd());
    shuffle(word.begin(), word.end(), g);
    return word;
}

// Function to play the game
void playGame(int difficulty, string playerName) {
    string hint;
    string originalWord = getRandomWord(hint);
    string scrambledWord = scrambleWord(originalWord);
    string userGuess;

    int timeLimit = (difficulty == 1) ? 40 : (difficulty == 2) ? 30 : 20;
    int points = (difficulty == 1) ? 10 : (difficulty == 2) ? 20 : 30;
    int attempts = 3;
    bool hintUsed = false;

    cout << "\nUnscramble the word: " << scrambledWord << endl;
    cout << "You have " << timeLimit << " seconds to guess the correct word!\n";

    auto startTime = high_resolution_clock::now();

    while (attempts > 0) {
        cout << "Your guess (or type 'hint' to get a clue): ";
        cin >> userGuess;

        auto currentTime = high_resolution_clock::now();
        double timeElapsed = duration<double>(currentTime - startTime).count();

        if (timeElapsed > timeLimit) {
            cout << "Time is up! The correct word was: " << originalWord << "\n\n";
            return;
        }

        if (userGuess == "hint" && !hintUsed) {
            cout << "Hint: " << hint << "\n";
            points -= 5;
            hintUsed = true;
            continue;
        } else if (userGuess == "hint" && hintUsed) {
            cout << "You've already used a hint!\n";
            continue;
        }

        if (userGuess == originalWord) {
            cout << "Congratulations, " << playerName << "! You guessed it correctly in " << timeElapsed << " seconds.\n";
            leaderboard[playerName] += points;
            cout << "Current Score: " << leaderboard[playerName] << " points\n";
            return;
        } else {
            attempts--;
            cout << "Wrong guess! Attempts left: " << attempts << "\n";
        }
    }

    cout << "Out of attempts! The correct word was: " << originalWord << "\n";
}

// Function to display the leaderboard
void displayLeaderboard() {
    if (leaderboard.empty()) {
        cout << "No scores recorded yet.\n";
        return;
    }
    for (const auto& entry : leaderboard) {
        cout << entry.first << " : " << entry.second << " points\n";
    }
}

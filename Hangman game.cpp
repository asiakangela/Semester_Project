#include <iostream>
#include <string>
#include <vector>

class HangmanGame {
private:
    std::string hiddenWord;
    std::string guessedWord;
    int maxGuesses;
    int currentGuess;

public:
    HangmanGame(const std::string& word, int maxGuessCount)
        : hiddenWord(word), maxGuesses(maxGuessCount), currentGuess(0) {
        guessedWord = std::string(word.length(), '_');
    }

    bool makeGuess(char letter) {
        bool correctGuess = false;
        for (size_t i = 0; i < hiddenWord.length(); ++i) {
            if (hiddenWord[i] == letter) {
                guessedWord[i] = letter;
                correctGuess = true;
            }
        }
        if (!correctGuess) {
            ++currentGuess;
        }
        return correctGuess;
    }

    bool isGameOver() const {
        return currentGuess >= maxGuesses || guessedWord == hiddenWord;
    }

    std::string getGuessedWord() const {
        return guessedWord;
    }

    void displayHangman() const {
        // Implement hangman figure drawing here
    }

    void displayGameStatus() const {
        std::cout << "Guessed word: " << guessedWord << std::endl;
        std::cout << "Guesses left: " << maxGuesses - currentGuess << std::endl;
    }
};

int main() {
    std::string secretWord = "hangman";
    int maxGuesses = 6;

    HangmanGame game(secretWord, maxGuesses);

    while (!game.isGameOver()) {
        game.displayGameStatus();

        char guess;
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (game.makeGuess(guess)) {
            std::cout << "Correct guess!" << std::endl;
        } else {
            std::cout << "Incorrect guess." << std::endl;
            game.displayHangman();
        }
    }

    if (game.isGameOver() && game.getGuessedWord() == secretWord) {
        std::cout << "Congratulations! You guessed the word: " << secretWord << std::endl;
    } else {
        std::cout << "Game over! The word was: " << secretWord << std::endl;
    }
return 0;
}


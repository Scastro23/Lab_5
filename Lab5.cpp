// Samuel Castro
// Lab 5 
// FA2023
/* Description: Write a number-guessing game in which the computer selects a random
number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
the end of each game, users should be told whether they won or lost, and then be asked
whether they want to play again. When the user quits, the program should output the
total number of wins and losses. To make the game more interesting, the program
should vary the wording of the messages that it outputs for winning, for losing, and for
asking for another game.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Messages.h"

class NumberGuessingGame {
public:
    // Constructor to initialize game state
    NumberGuessingGame() : wins(0), losses(0) {
        srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    }

    // Function to play the game
    void playGame() {
        int targetNumber = rand() % 101; // Generate a random number between 0 and 100
        int guess;
        int attempts = 0;
        bool hasWon = false;

        // Main game loop
        do {
            std::cout << "Enter your guess (0-100): ";
            std::cin >> guess;

            // Check for invalid input
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                std::cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            attempts++;

            // Check if the guess is correct
            if (guess == targetNumber) {
                hasWon = true;
                break;
            }
            else if (guess < targetNumber) {
                std::cout << "Too low! Try again.\n";
            }
            else {
                std::cout << "Too high! Try again.\n";
            }

        } while (attempts < 20);

        // Display appropriate message based on the result
        if (hasWon) {
            std::cout << Messages::getRandomWinMessage() << "\n";
            wins++;
        }
        else {
            std::cout << Messages::getRandomLoseMessage() << "\n";
            losses++;
        }
    }

    // Function to start the game loop
    void startGame() {
        char playAgain;

        // Outer loop for restarting the game
        do {
            playGame();

            std::cout << Messages::getRandomAskMessage() << " (y/n): ";
            std::cin >> playAgain;

        } while (playAgain == 'y' || playAgain == 'Y');

        // Display total wins and losses when the user quits
        std::cout << "Total Wins: " << wins << "\n";
        std::cout << "Total Losses: " << losses << "\n";
    }

private:
    int wins;
    int losses;
};

int main() {
    NumberGuessingGame game;
    game.startGame();

    return 0;
}

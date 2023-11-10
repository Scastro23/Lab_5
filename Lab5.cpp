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

class NumberGuessingGame {
private:
    int wins;
    int losses;

    // Function to display a random winning message
    void displayWinMessage() {
        srand(time(0)); // Seed for random number generation
        std::string winMessages[] = {
            "Congratulations! You guessed it right!",
            "You're a mastermind! You won this round!",
            "Victory is yours! Well done!",
            "Fantastic! You cracked the code!",
            "Bravo! You're the number-guessing champion!",
            "Incredible! You've mastered the guessing game!",
            "Awesome! Your intuition is spot on!",
            "Hooray! Another triumph for your guessing skills!",
            "You're unstoppable! Another win in the bag!",
            "Outstanding! Your guessing prowess is unmatched!"
        };

        int randomIndex = rand() % 10;
        std::cout << winMessages[randomIndex] << std::endl;
    }

    // Function to display a random losing message
    void displayLoseMessage() {
        srand(time(0)); // Seed for random number generation
        std::string loseMessages[] = {
            "Oops! You ran out of attempts. Better luck next time!",
            "Not this time, but don't give up!",
            "You didn't quite get it, but practice makes perfect!",
            "No worries, it happens! Try again!",
            "Better luck next round! You're getting closer!",
            "Don't be discouraged! The next guess might be the one!",
            "Missed it this time, but your persistence is commendable!",
            "It's okay! Every attempt is a step toward improvement.",
            "No victory this time, but the challenge continues!",
            "Learning from setbacks is the key to eventual success!"
        };

        int randomIndex = rand() % 10;
        std::cout << loseMessages[randomIndex] << std::endl;
    }

    // Function to display a random play again message
    void displayPlayAgainMessage() {
        srand(time(0)); // Seed for random number generation
        std::string playAgainMessages[] = {
            "Want to play again? (yes/no): ",
            "Ready for another round? (yes/no): ",
            "Feel like trying again? (yes/no): ",
            "Up for another challenge? (yes/no): ",
            "Ready to test your luck again? (yes/no): ",
            "Eager for another game? (yes/no): ",
            "Curious for more challenges? (yes/no): ",
            "Excited for another round? (yes/no): ",
            "Fancy another attempt? (yes/no): ",
            "Up for the challenge once more? (yes/no): "
        };

        int randomIndex = rand() % 10;
        std::cout << playAgainMessages[randomIndex];
    }

public:
    // Constructor to initialize wins and losses
    NumberGuessingGame() : wins(0), losses(0) {}

    // Function to play the number-guessing game
    void playGame() {
        do {
            int secretNumber = rand() % 101; // Random number between 0 and 100
            int attempts = 20;
            bool won = false;

            while (attempts > 0) {
                int guess;
                std::cout << "Guess the number (0-100). You have " << attempts << " attempts left: ";
                std::cin >> guess;

                if (guess == secretNumber) {
                    won = true;
                    break;
                }
                else if (guess < secretNumber) {
                    std::cout << "Too low! Try again." << std::endl;
                }
                else {
                    std::cout << "Too high! Try again." << std::endl;
                }

                attempts--;
            }

            if (won) {
                wins++;
                displayWinMessage();
            }
            else {
                losses++;
                displayLoseMessage();
            }

            displayPlayAgainMessage();

            std::string playAgain;
            do {
                std::cout << "Play again? (yes/no): ";
                std::cin >> playAgain;
            } while (playAgain != "yes" && playAgain != "no");

            if (playAgain == "no") {
                break;
            }

        } while (true);

        std::cout << "\nTotal Wins: " << wins << "\nTotal Losses: " << losses << std::endl;
    }
};

int main() {
    NumberGuessingGame game;
    game.playGame();

    return 0;
}


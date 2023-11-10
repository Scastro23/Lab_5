#include "Lab5.h"
#include <cstdlib>
#include <ctime>

void NumberGuessingGame::displayMessage(std::string result) {
    srand(time(0)); // Seed for random number generation

    std::string winMessages[] = {
        "Congratulations! You guessed it right!";
        "You're a mastermind! You won this round!";
        "Victory is yours! Well done!";
        "Fantastic! You cracked the code!";
        "Congratulations! You've guessed the number correctly!";
        "Great job! You've won!";
        "Excellent work! You've cracked the code!";
        "Bravo! Your coding skills have triumphed!";
        "Vamoss!! You are Goated!";
        "You've cracked it! Brilliant win!
    };

    std::string loseMessages[] = {
        "Oops! You ran out of attempts. Better luck next time!";
        "Not this time, but don't give up!";
        "You didn't quite get it, but practice makes perfect!";
        "No worries, it happens! Try again!";




    };

    std::string playAgainMessages[] = {
        "Want to play again? (yes/no): ",
        "Ready for another round? (yes/no): ",
        "Feel like trying again? (yes/no): ",
        "Up for another challenge? (yes/no): "
        "Do you want to play again? (yes/no): ";
        "Ready for more coding fun? Another round? (yes/no): ";
        "Feel like another game? Let's code on! (yes/no): ";
        "Another round? Let's keep coding! (yes/no): ";
        "Feeling up for another game? Let's code! (yes/no): ";
        "Want to try again? Let's keep coding! (yes/no): ";
    };

    int randomIndex = rand() % 4;

    switch (result[0]) {
    case 'w':
        std::cout << winMessages[randomIndex] << std::endl;
        break;
    case 'l':
        std::cout << loseMessages[randomIndex] << std::endl;
        break;
    default:
        std::cout << playAgainMessages[randomIndex];
    }
}

void NumberGuessingGame::playGame() {
    do {
        int secretNumber = rand() % 101; // Random number between 0 and 100
        int attempts = 20;
        std::string result = "";

        while (attempts > 0) {
            int guess;
            std::cout << "Guess the number (0-100). You have " << attempts << " attempts left: ";
            std::cin >> guess;

            if (guess == secretNumber) {
                result = "win";
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

        if (result == "win") {
            wins++;
        }
        else {
            losses++;
        }

        displayMessage(result);

        std::string playAgain;
        std::cout << "Play again? (yes/no): ";
        std::cin >> playAgain;

    } while (playAgain == "yes");

    std::cout << "\nTotal Wins: " << wins << "\nTotal Losses: " << losses << std::endl;
}
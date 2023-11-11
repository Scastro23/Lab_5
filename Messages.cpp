#include "Messages.h"
#include <cstdlib>

// Different win messages
std::string winMessages[] = {
    "Congratulations! You guessed it!",
    "You're a winner! Great job!",
    "Hooray! You won!",
    "Congratulations! You guessed it right!",
    "You're a mastermind! You won this round!",
    "Victory is yours! Well done!",
    "Fantastic! You cracked the code!",
    "Bravo! You're the number-guessing champion!",
    "Incredible! You've mastered the guessing game!",
    "Awesome! Your intuition is spot on!",
};

// Different lose messages
std::string loseMessages[] = {
    "Sorry, you lost. Better luck next time!",
    "No worries. You'll get it next time!",
    "Hard luck! You didn't win this time.",
    "Oops! You ran out of attempts. Better luck next time!",
    "Not this time, but don't give up!",
    "You didn't quite get it, but practice makes perfect!",
    "No worries, it happens! Try again!",
    "Better luck next round! You're getting closer!",
    "Don't be discouraged! The next guess might be the one!",
    "Missed it this time, but your persistence is commendable!",
};

// Different ask messages
std::string askMessages[] = {
    "Do you want to play again?",
    "Ready for another round?",
    "Feeling lucky? Want to play one more time?",
    "Want to play again? (yes/no): ",
    "Ready for another round? (yes/no): ",
    "Feel like trying again? (yes/no): ",
    "Up for another challenge? (yes/no): ",
    "Ready to test your luck again? (yes/no): ",
    "Eager for another game? (yes/no): ",
    "Curious for more challenges? (yes/no): ",
};

// Function to get a random winning message
std::string Messages::getRandomWinMessage() {
    // Switch statement to choose a random win message
    switch (rand() % (sizeof(winMessages) / sizeof(winMessages[0]))) {
    case 0: return winMessages[0];
    case 1: return winMessages[1];
        
    default: return winMessages[2];
    }
}

// Function to get a random losing message
std::string Messages::getRandomLoseMessage() {
    // Switch statement to choose a random lose message
    switch (rand() % (sizeof(loseMessages) / sizeof(loseMessages[0]))) {
    case 0: return loseMessages[0];
    case 1: return loseMessages[1];
       
    default: return loseMessages[2];
    }
}

// Function to get a random asking message
std::string Messages::getRandomAskMessage() {
    // Switch statement to choose a random ask message
    switch (rand() % (sizeof(askMessages) / sizeof(askMessages[0]))) {
    case 0: return askMessages[0];
    case 1: return askMessages[1];
        
    default: return askMessages[2];
    }
}

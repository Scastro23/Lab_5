#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

// Declaration of the Messages class
class Messages {
public:
    // Function to get a random winning message
    static std::string getRandomWinMessage();

    // Function to get a random losing message
    static std::string getRandomLoseMessage();

    // Function to get a random asking message
    static std::string getRandomAskMessage();
};

#endif // MESSAGES_H

// ROCK PAPER SCISSORS GAME

#include <iostream>
#include <unistd.h> // usleep() - MICROSECONDS (1s = 10^6)

// Choice ENUM + enum to string function
enum Choice { ROCK = 1, PAPER, SCISSORS };
const std::string enterToRestart = "Please press ENTER to continue...\n";

std::string choiceToString(Choice choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return "";
    }
}

// Returns 1-3
int generateChoice() { 
    return (std::rand() % 3) + 1; // not random but will switch to another number
}

int getIntInput() {
    int input;
    while (true) {
        std::cout << "Enter an integer: ";
        std::cin >> input;

        // Check if input is valid
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        } else {
            std::cin.ignore(10000, '\n');
            return input;
        }
    }
}

bool playerWon(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return false; // tie
    }

    if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
        (playerChoice == PAPER && computerChoice == ROCK) ||
        (playerChoice == SCISSORS && computerChoice == PAPER)) {
        return true; // you won!!
    } else {
        return false; // you lost :(
    }
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Restart prompt and clears console
void endGame() {
    std::cout << enterToRestart;
    std::cin.get();
    clearScreen();
}

int main() {
    clearScreen();
    std::cout << "Welcome to Rock Paper Scissors!\n";
    std::cout << "Please select one of the following options:\n";
    std::cout << "1. Rock\n";
    std::cout << "2. Paper\n";
    std::cout << "3. Scissors\n";

    int userChoice = getIntInput(); // 1-3
    if (userChoice > 3 || userChoice < 1) {
        // invalid choice lmao
        std::cout << "Please give valid input!\n";
        endGame();
        return 0;
    }
    int computersChoice = generateChoice();
    bool result = playerWon(userChoice, computersChoice);
    
    std::cout << "You've chosen " << choiceToString(Choice(userChoice)) << "\n"; // could be better

    std::cout << "AND THE OUTCOME ISSS......\n";
    usleep(1000000);
    std::cout << "Opponent used " << choiceToString(Choice(computersChoice)) << "\n";
    
    if (result) {
        std::cout << "You've won!\n";
        endGame();
    } else {
        // failed :(
        std::cout << "You've lost :(\n";
        endGame();
    }
    return 0;
}
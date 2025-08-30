#include <iostream>
#include <string>

// Entry point of the gambling app
int main() {
    // Welcome message
    std::cout << "Welcome to the Gambling App!" << std::endl;

    // User name input
    std::string userName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);

    // Greet the user
    std::cout << "Hello, " << userName << "! Let's start gambling." << std::endl;

    // Bank mechanic
    int bank = 100;
    std::cout << "Your starting bank: $" << bank << std::endl;

    bool running = true;
    while (running && bank > 0) {
        std::cout << "\nMain Menu:" << std::endl;
        std::cout << "1. Play Slot Machine" << std::endl;
        std::cout << "2. Play Roulette" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Bank: $" << bank << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Slot Machine
                int bet;
                std::cout << "Enter your bet (max $" << bank << "): ";
                std::cin >> bet;
                if (bet <= 0 || bet > bank) {
                    std::cout << "Invalid bet amount." << std::endl;
                    break;
                }
                bank -= bet;
                // Visual slot machine
                const char* symbols[] = {"🍒", "🍋", "🔔", "⭐", "💎"};
                int s1 = rand() % 5;
                int s2 = rand() % 5;
                int s3 = rand() % 5;
                std::cout << "Spinning...\n";
                std::cout << "[" << symbols[s1] << "] [" << symbols[s2] << "] [" << symbols[s3] << "]" << std::endl;
                if (s1 == s2 && s2 == s3) {
                    int win = bet * 10;
                    std::cout << "Jackpot! You win $" << win << "!" << std::endl;
                    bank += win;
                } else if (s1 == s2 || s2 == s3 || s1 == s3) {
                    int win = bet * 2;
                    std::cout << "Nice! You win $" << win << "!" << std::endl;
                    bank += win;
                } else {
                    std::cout << "No win. Better luck next time!" << std::endl;
                }
                break;
            }
            case 2: {
                // Roulette
                int bet;
                std::cout << "Enter your bet (max $" << bank << "): ";
                std::cin >> bet;
                if (bet <= 0 || bet > bank) {
                    std::cout << "Invalid bet amount." << std::endl;
                    break;
                }
                std::cout << "Bet on (1) Red or (2) Black: ";
                int color;
                std::cin >> color;
                if (color != 1 && color != 2) {
                    std::cout << "Invalid choice." << std::endl;
                    break;
                }
                bank -= bet;
                int spin = rand() % 2 + 1; // 1: Red, 2: Black
                std::cout << "Spinning the wheel...\n";
                std::cout << "Result: " << (spin == 1 ? "Red" : "Black") << std::endl;
                if (spin == color) {
                    int win = bet * 2;
                    std::cout << "You win $" << win << "!" << std::endl;
                    bank += win;
                } else {
                    std::cout << "You lose. Better luck next time!" << std::endl;
                }
                break;
            }
            case 3:
                std::cout << "Thank you for playing! Goodbye." << std::endl;
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
        if (bank <= 0) {
            std::cout << "You are out of money! Game over." << std::endl;
            running = false;
        }
    }
    return 0;
}
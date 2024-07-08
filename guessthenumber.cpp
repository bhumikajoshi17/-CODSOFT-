#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Initialize random seed based on current time
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    // Loop until the user guesses the correct number
    while (userGuess != randomNumber) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try again." << std::endl;
        } else if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
        }
    }

    return 0;
}

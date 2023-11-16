// Copyright (c) 2023 Santiago Hewett All rights reserved.
//
// Created by: Santiago Hewett
// Date: Nov, 15, 2023
// This program will ask the user
// for a number and will check if it is not a integer
// and then tell the user if they guessed correctly using random number

#include <iostream>

// Include this for std::setprecision

#include <iomanip>
#include <random>

int main() {
    // Declare userGuessStr and userGuessInt
    std::string userGuessStr;
    int userGuessInt;

    // Create a random seed value
    std::random_device rd;

    // Create the sequence for the number generator
    std::mt19937 gen(rd());

    // Declare constants
    const int MIN_NUMBER = 0;
    const int MAX_NUMBER = 9;

    // Create a distribution between 0 and 9
    std::uniform_int_distribution<int> distribution(MIN_NUMBER, MAX_NUMBER);

    // Generate correctGuess
    int correctGuess = distribution(gen);

    do {
        // Get the userGuessStr and display a message about the program
        std::cout << "This program will ask the user for a number between 0 "
                  << "and 9 "
                  << "and it will tell them if they guessed my "
                  << "number correctly."
                  << "\nEnter your whole number: ";
        std::cin >> userGuessStr;

        try {
            // Convert userGuessStr to int
            userGuessInt = std::stoi(userGuessStr);

            // Check if user number is negative or not in the right range
            if (userGuessInt < 0 || userGuessInt > 9) {
                std::cout << userGuessInt
                          << " is not a valid number. Please enter "
                          << "a number between 0 and 9."
                          << std::endl;
            } else if (userGuessInt != correctGuess) {
                // Display it was not the correct guess
                std::cout << userGuessInt << " is not the" << std::endl;
                std::cout << "correct guess." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            // Display that the user number was not a valid int
            std::cout << userGuessStr << " is not a valid int." << std::endl;
        }
    } while (userGuessInt != correctGuess);

    // Display that the guess was correct
    std::cout << userGuessInt << " is correct." << std::endl;
}

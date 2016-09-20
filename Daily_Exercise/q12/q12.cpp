// A program that prompts the user to enter 's' or 'c'. You should continue to prompt the user to enter 's' or 'c' until one of these characters is entered or until ‘q’ is entered.

#include <iostream>
#include <math.h>

int main() {
    std::string input;      // Input character.
    int num = 0;
    
    std::cout << "Please enter 's' or 'c', or 'q' to quit the program: ";
    std::cin >> input;
    
    while (input != "q" && input != "c" && input != "s") {
        std::cout << "Please enter 's' or 'c', or 'q' to quit the program: ";
        std::cin >> input;
    }
    
    if (input == "q") {
        exit(1);
    }
    else if (input == "s" || input == "c") {
        std::cout << "Please enter a number: ";
        std::cin >> num;
        
        if (input == "s") {
            std::cout << sin(num) << std::endl;
        }
        else if (input == "c") {
            std::cout << cos(num) << std::endl;
        }
    }
    
    return 0;
}
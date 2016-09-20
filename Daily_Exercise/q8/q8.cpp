#include <iostream>
#include <string>

int main() {

    // An array of 5 characters on the heap.
    char str[] = "apple";
    char *x = str;
    char **y = &x;  // A pointer y in the stack pointing to x, which points to an array of 5 characters.
    int sum = 0;    // Sum up the ASCII characters, initialize to 0.
    
    for (int i = 0; i < 5; i++) {
        sum += x[i];
        std::cout << sum << " " << x[i] << std::endl;
    }
    
    std::cout << "The value of y is " << y << "." << std::endl;
    std::cout << "The sum of the characters is " << sum << "." << std::endl;
    
    delete x;
    delete y;
    
    return 0;
}
#include <iostream>

int main() {
    int x = 2016;  // Define an integer x in stack, and initialize it with value 2016.
    int *p = &x;     // Define an integer pointer p on the stack, and assigns it to point to x.
    
    // Print out the address of x and the value of x.
    std::cout << "x is stored at address " << &x << " and has value " << x << std::endl;
    
    *p = 2017;      // Change the value of x to 2017 via p.
    
    // Prints the address of x and its value via p.
    std::cout << "x is stored at address " << p << " and has value " << *p << std::endl;
    
    return 0;
}
#include <iostream>

int main() {
    int *p = NULL;      // Define a null pointer
    
    *p = 1;     // Assign the value of the null pointer p to be 1, which leads to segmentation fault since I am assigning a value to a pointer which is not pointing anywhere.
    
    return 0;
}
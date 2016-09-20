/* Write a function raise (not a program) that accepts an array of integers and an integer as the input parameters
 
 The input array will have exactly one negative value as the very last element of the array
 The function should create an array on the heap that contains the values of the input array each raised to the power of the second input parameter (besides the last negative element of the original array which should remain the same in the new array)
 
 (HINT: there is a library function that might help you with this)
 Return the starting address of this array
 Include any libraries you use at the top of the file
 
 */

#include <iostream>
#include <math.h>

int* raise() {
    int x = 0, n = 0, count = 1, num_power = 0;
    int *int_arr = new int[count];
    
    std::cout << "Please input an array of integers, each integer followed by an enter.  Input a negative integer indicating the last element of the array." << std::endl;
    
    do {
        std::cin >> x;
        
        int_arr[n] = x;   // Fill up the integer to the last element of the array.
        n++;
        
        if (n >= count) {
            count++;
            int *temp = new int[count];
            
            for (int j = 0; j < n; j++) {
                temp[j] = int_arr[j];
            }
            
            delete[] int_arr;       // Delete the array, frees memory.
            int_arr = temp;
        }
    } while (x >= 0);
    
    std::cout << "Please input a second input, in which the array elements are raised to the power of: ";
    std::cin >> num_power;
    
    for (int i = 0; i < n; i++) {
        std::cout << i << " " << int_arr[i] << std::endl;
    }
    
    int *heap_arr = new int[n - 1];
    
    for (int i = 0; i < n-1; i++) {
        heap_arr[i] = pow(int_arr[i], num_power);
        std::cout << i << " " << heap_arr[i] << " " << &heap_arr[i] << std::endl;
    }
    
    delete[] int_arr;
    return &heap_arr[0];
    
    delete[] heap_arr;
}

int main() {
    raise();
    return 0;
}

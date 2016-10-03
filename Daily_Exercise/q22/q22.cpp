#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Find the maximum from the array
int max(int arr[]) {
    int i = 0, count = 0, maximum = 0, alpha_num = 26;
    for (i = 0; i < alpha_num; i++) {
        // This ensures the alphabetically first letter is printed out.
        if (maximum < arr[i]) {
            maximum = arr[i];
            count = i;
        }
    }
    return count;
}

int main() {
    int i = 0, x = 0, alpha_num = 26, a_ASC = 97;
    string str;
    
    // Get the string input.
    getline(cin, str);
    
    // An array to store the counts of characters. There are 26 alphabets.
    int str_count[alpha_num];
    
    for (int k = 0; k < alpha_num; k++) {
        str_count[k] = 0;
    }
    
    // Convert the characters to lower cases.
    while (str[i]) {
        str[i] = tolower(str[i]);
        x = str[i];     // Get the ASCII code of the alphabet.
        // cout << str[i] << " " << x << endl;
        // It corresponds to a to z in the ASCII code
        if (x >= a_ASC || x < a_ASC + alpha_num) {
            str_count[x - a_ASC]++;
        }
        i++;
    }
    
    // The most frequent character.
    char asciiChar = max(str_count) + a_ASC;
    
    cout << "The most frequency character is " << asciiChar << endl;
    
    return 0;
}
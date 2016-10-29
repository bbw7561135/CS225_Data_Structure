#include "func.h"

string secretKey(){
    string str = "purplerocks";     // Secret Key.
    cout << "The secret key is " << str << endl;            // Print the secret key.
    return str;
}

void encrypt(string str){
    int i = 0;
    while (str[i]) {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122) {
            cout << "Secret Key can only be made up of upper and lowercase letters." << endl;
            exit(1);
        }
        i++;
    }
    
    i = 0;
    while (str[i]) {
        str[i] = str[i] + 7;        // Increase the ASCII key by 7.
        i++;
    }
    cout << "The encryption of the secret key is " << str << endl;
}

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int myhash(string str){     // many different hash fucntions acceptable, this is just an example
    // The fate is determined by the total of the ascii value of the characters, with modulus of 5.
    int i = 0, asc_val = 0;
    while (str[i]) {
        asc_val += str[i];
        i++;
    }
    return asc_val % 5;
}

int main(){
    cout << "State your question: ";
    string in;
    getline(cin, in);
    // put error checking code here...
    
    int i = 0;
    
    // Count the number of characters.
    while (in[i]) {
        i++;
    }
    
    // The string has to be less than or equal to 100 characters, but greater than 1.
    if (i <= 1 || i > 100) {
        cout << "The string has to be less than or equal to 100 characters, but greater than 1!" << endl;
        return 1;
    }
    
    // The string has to be ended with a Question Mark.  ASCII code of question mark is 63.
    if (in[i-1] != 63) {
        cout << "The string has to be ended with a Question Mark!" << endl;
        return 1;
    }
    
    int val = myhash(in);

    cout << in << " hashed to value " << val << endl;
    if(val == 0)
        cout << "The outlook is bleak." << endl;
    else if(val == 1)
        cout << "The answer is most likely yes." << endl;
    else if(val == 2)
        cout << "Is today Tuesday? If yes, then yes! Otherwise, probably not." << endl;
    else if(val == 3)
        cout << "Most definitely!" << endl;
    else
        cout << "The future in unclear at the moment. Try again later." << endl;
    return 0;
}

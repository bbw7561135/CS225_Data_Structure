#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int x, mod, count = 0, a = 0, b = 0, c = 0;
    cout << "Enter a positive integer: " << endl;
    cin >> x;
    
    int *arr = new int[x];
    
    for (int i = 0; i < x; i++) {
        arr[i] = 0;     // Initialization.
    }
    
    for (int i = 1; i <= x; i++) {
        mod = x % i;    // If modulus = 0, then x is divisible by i, makr arr[i-1] as 1.
        if (mod == 0) {
            arr[i-1] = 1;
            count++;
        }
    }
    
    // Prime number.
    if (count == 2) {
        cout << x << " is prime" << endl;
    }
    else {
        for (int i = 0; i < x-1; i++) {
            if (arr[i] == 1) {
                cout << i+1 << " ";
            }
        }
        cout << "divide " << x << endl;
    }
    
    delete []arr;
    
    // Write 3 inputs in "testcases.txt".
    ofstream outfile;
    outfile.open ("testcases.txt");
    
    // Chose these three numbers to test for prime and divisible cases.
    a = 13;     // 13 is prime.
    b = 21;     // 1 3 7 divide 21
    c = 179;    // 179 is prime.
    
    
    outfile << a << endl;
    outfile << b << endl;
    outfile << c;
    
    outfile.close();


    return 0;
}

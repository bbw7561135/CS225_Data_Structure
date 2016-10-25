#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Write two lines to the file.
    ofstream outfile;
    outfile.open ("test.txt");
    
    string str1 = "Hi there!\n";
    string str2 = "Anyone around?";
    
    outfile << str1 << str2;
    
    outfile.close();
    
    
    // Read from the file and print them out.
    string line;
    
    ifstream infile;
    infile.open ("test.txt");
    
    if (infile.is_open()) {
        while (getline (infile, line)) {
            cout << line << endl;
        }
        infile.close();
    }
    
    return 0;
}
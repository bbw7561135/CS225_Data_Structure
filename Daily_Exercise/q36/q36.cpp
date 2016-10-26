#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    // Read the "text.txt" file.
    string textstr, str;
    
    ifstream infile;
    infile.open ("text.txt");
    
    if (infile.is_open()) {
        while (getline (infile, textstr)) {
            if (textstr == "purple") {
                cout << textstr << endl;
                str = textstr;
            }
        }
        infile.close();
    }
    
    
    // Write in "testcases.txt"
    ofstream outfile;
    outfile.open ("testcases.txt");
    
    outfile << str << endl;
    
    outfile.close();

    return 0;
}

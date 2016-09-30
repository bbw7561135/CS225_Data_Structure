#include <iostream>

using namespace std;

int main() {
    
    int n;
    cout << "n = ";
    cin >> n;   // Input the integer representing the row / column of the matrix.
    
    // Create the 2D matrix of size nxn in the heap.
    int **mat = new int*[n];
    
    for (int i = 0; i < n; i++) {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++) {
            mat[i][j] = i + j;
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Clear the memories in the heap.
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    
    delete[] mat;
    
    
    return 0;
}
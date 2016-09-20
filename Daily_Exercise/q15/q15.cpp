// Assignment operators are overloaded so the programmer can define the operation he wishes and the syntax could be made much simpler.

#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
        Square & operator = (const Square &S);       // = operator
        Square operator + (const Square &S);       // = operator
};

Square::Square(){
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

// = operator definition.
Square & Square::operator = (const Square &S) {
    
    // Check for self-assignment
    if (this == &S)
        return *this;
    
    // Need to deallocate any value that this pointer is holding.
    delete lengthptr;
    
    // Shallow copy name.
    name = S.name;
    
    // The pointer needs to be deep copied.
    if (S.lengthptr) {
        lengthptr = new double;
        *lengthptr = *(S.lengthptr);
    }
    else
        lengthptr = 0;
    
    return *this;
}

// + operator definition.
Square Square::operator + (const Square &S) {
    
    Square tmp_obj = *this;
    
    // Add the lengths of the two squares, and concatenate the names.
    *(tmp_obj.lengthptr) += *(S.lengthptr);
    tmp_obj.name += S.name;
    
    return tmp_obj;
}

void Square::setName(string newName){name = newName;}
void Square::setLength(double newVal){*lengthptr = newVal;}
string Square::getName() const {return name;}
double Square::getLength() const {return *lengthptr;}

Square::Square(const Square & other){
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square(){
    delete lengthptr;
}


int main(){
    Square a;
    Square b;
    b = a;
    Square c(a);
    Square d = a + b;
    return 0;
}

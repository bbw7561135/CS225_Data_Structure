#include <iostream>

// Square class
class square {
    public:
        square();
        square(const square &obj);      // Copy constructor.
        ~square();
        std::string getname();
        double getlength();
    private:
        double *length;
        std::string name;
};

// Default constructor.
square::square() {
    //std::cout << "Default constructor" << std::endl;
    // Allocate memory for the length pointer.
    length = new double;
    *length = 2.0;
    name = "mysquare";
}

square::square(const square &obj) {
    std::cout << "I am copying!" << std::endl;
    length = new double;
    *length = *obj.length;
    name = obj.name;
}

// Destructor.
square::~square() {
    //std::cout << "Freeing memory!" << std::endl;
    delete length;
}

std::string square::getname() {
    return name;
}

double square::getlength() {
    return *length;
}


int main() {
    square Sq;
    square Sq2 = Sq;

	return 0;
}

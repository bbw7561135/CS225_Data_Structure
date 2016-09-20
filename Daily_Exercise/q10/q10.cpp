// Your code here

#include <iostream>
#include <string>

class Food {    // begin declaration of the class
public:
    Food(int initialQuantity, std::string initialName);     // Default constructor
    ~Food();    // Default destructor
    
    int Getquantity() const;    // Accessor function
    std::string Getname() const;
    
private:
    int quantity;
    std::string name;
};

Food::Food(int initialQuantity, std::string initialName) {
    // Constructor of Food
    quantity = initialQuantity;
    name = initialName;
}

Food::~Food() {     // Destructor of Food
    //delete[] name;
}

int Food::Getquantity() const {      // Get quantity of the food.
    return quantity;
}

std::string Food::Getname() const {      // Get name of the food.
    return name;
}

void increaseQuantity(Food *fod) {
    // Increases the quantity of the food, pass the food object BY POINTER.
    int x = fod->Getquantity();
    x++;
    std::cout << "You have " << x << " " << fod->Getname() << "." << std::endl;
}


int main() {
    // Create an instance of the food class.
    Food Fruit(5, "apples");
    std::cout << "You have " << Fruit.Getquantity() << " " << Fruit.Getname() << "." << std::endl;
    increaseQuantity(&Fruit);
    
    return 0;
}


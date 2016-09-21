#include <iostream>
using namespace std;

// A base class
class Animal {
    private:
        string animal_type;     // This variable can only be changed by the functions of the animal class.
    protected:
        string food_type;   // This variable is accessible also by the derived classes.
    public:
        Animal();       // Default constructor.
        ~Animal();
        Animal(string an_type, string fd_type); // A constructor that has parameters
        string GetAnimal_type() const;      // Accessor of animal type
        string GetFood_type() const;        // Accessor of food type
        void SetAnimal_type(string newAntype);      // Mutator of animal type
        void SetFood_type(string newFdtype);        // Mutator of food type
        virtual void print();       // This has to be a virtual function so the derived class can override it.
};

// A derived class
class mammal : public Animal {
    public:
        void print();
};

// Default constructor
Animal::Animal() {
    animal_type = "cat";
    food_type = "fish";
}

// Destructor
Animal::~Animal() {}

Animal::Animal(string an_type, string fd_type) {
    animal_type = an_type;
    food_type = fd_type;
}

string Animal::GetAnimal_type() const {return animal_type;}
string Animal::GetFood_type() const {return food_type;}
void Animal::SetAnimal_type(string newAntype) {animal_type = newAntype;}
void Animal::SetFood_type(string newFdtype) {food_type = newFdtype;}
void Animal::print() {cout << "I am a " << animal_type << "." << endl;}
void mammal::print() {
    //cout << "I am a " << animal_type << "." << endl;      // Compiler error as animal_type is not accessible to the derived class.
    cout << "I eat " << food_type << "." << endl;       // This is OK since food_type is a protected class.
}


/*
int main() {
    Animal an;  // Test the default constructor
    Animal bn("dog", "bone");   // Test the other constructor
    cout << an.GetAnimal_type() << " " << an.GetFood_type() << endl;
    cout << bn.GetAnimal_type() << " " << bn.GetFood_type() << endl;
    
    an.SetAnimal_type("bear");      // Test the mutator
    an.SetFood_type("meat");
    cout << an.GetAnimal_type() << " " << an.GetFood_type() << endl;
    
    an.print();
    
    mammal cn;      // Check the derived class.
    cn.print();     // print() has been overridden.
    cout << cn.GetAnimal_type() << endl;
    
    return 0;
}*/


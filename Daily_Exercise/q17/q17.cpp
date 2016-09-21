#include <iostream>
using namespace std;

// A base class
class Animal {
    protected:
        string animal_type;     // This variable can only be changed by the functions of the animal class.
        string food_type;   // This variable is accessible also by the derived classes.
    public:
        Animal();       // Default constructor.
        ~Animal();
        Animal(string an_type, string fd_type); // A constructor that has parameters
        /*string GetAnimal_type() const;      // Accessor of animal type
        string GetFood_type() const;        // Accessor of food type
        void SetAnimal_type(string newAntype);      // Mutator of animal type
        void SetFood_type(string newFdtype);        // Mutator of food type*/
        virtual void print();       // This has to be a virtual function so the derived class can override it.
};

// A derived class
class Pet : public Animal {
    public:
        Pet();       // Default constructor.
        ~Pet();
        Pet(string an_type, string fd_type, string pn_type, string on_type); // A constructor that has parameters
        string GetAnimal_type() const;      // Accessor of animal type
        string GetFood_type() const;        // Accessor of food type
        string GetPetName_type() const;        // Accessor of pet's name type
        string GetOwnerName_type() const;        // Accessor of Owner's name type
        void SetAnimal_type(string newAntype);      // Mutator of animal type
        void SetFood_type(string newFdtype);        // Mutator of food type
        void SetPetName_type(string newPNtype);        // Mutator of pet's name type
        void SetOwnerName_type(string newONtype);        // Mutator of Owner's name type
        void print();
    private:
        string pet_name;
        string owner_name;
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

// Default constructor
Pet::Pet() {
    animal_type = "cat";
    food_type = "fish";
    pet_name = "Fluffy";
    owner_name = "Cinda";
}

// Destructor
Pet::~Pet() {}

Pet::Pet(string an_type, string fd_type, string pn_type, string on_type) {
    animal_type = an_type;
    food_type = fd_type;
    pet_name = pn_type;
    owner_name = on_type;
}

string Pet::GetAnimal_type() const {return animal_type;}
string Pet::GetFood_type() const {return food_type;}
string Pet::GetPetName_type() const {return pet_name;}
string Pet::GetOwnerName_type() const {return owner_name;}
void Pet::SetAnimal_type(string newAntype) {animal_type = newAntype;}
void Pet::SetFood_type(string newFdtype) {food_type = newFdtype;}
void Pet::SetPetName_type(string newPNtype) {pet_name = newPNtype;}
void Pet::SetOwnerName_type(string newONtype) {owner_name = newONtype;}
void Pet::print() {cout << "My name is " << pet_name << "." << endl;}
void Animal::print() {cout << "I am a " << animal_type << "." << endl;}



int main() {
    Pet an;  // Test the default constructor
    Pet bn("cat", "fish", "Garfield", "George");   // Test the other constructor
    /*cout << an.GetAnimal_type() << " " << an.GetFood_type() << " " << an.GetPetName_type() << " " << an.GetOwnerName_type() << endl;
    cout << bn.GetAnimal_type() << " " << bn.GetFood_type() << " " << bn.GetPetName_type() << " " << bn.GetOwnerName_type() << endl;*/
    
    bn.Animal::print();     // Call the parent function being overridden
    bn.print();             // Call the overriding function
    
    return 0;
}


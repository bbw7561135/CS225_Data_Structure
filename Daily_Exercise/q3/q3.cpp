#include <string>
#include <iostream>
using namespace std;
class Pet{
	/* Your code here! */
    public:         // Wish these member functions to be accessible and used by the other parts of the code.
        void initialize(string name, string birth_year, string type, string owner_name);
        string set_birth_year();
        string get_birth_year();
        string set_name();
        string get_name();
        string set_type();
        string get_type();
        string set_owner_name();
        string get_owner_name();
    private:        // Wish to store the member variables to be accessible only under the class Pet, do not want the compiler to access these by the other parts of the program.  This is to ensure these variables are not assigned to the wrong values.
        string name;
        string birth_year;
        string type;
        string owner_name;
};

// Initialization function of the class Pet.
void Pet::initialize(string name, string birth_year, string type, string owner_name){
    this->name = name;
    this->birth_year = birth_year;
    this->type = type;
    this->owner_name = owner_name;
}

// Function to get birth year of the pet.
string Pet::get_birth_year() {
    return birth_year;
}

// Function to set birth year of the pet.
string Pet::set_birth_year() {
    string pet_birth_year = "";
    cout << "Please enter the birth year of the pet: ";
    getline(cin, pet_birth_year);
    return pet_birth_year;
}

// Function to get name of the pet.
string Pet::get_name() {
    return name;
}

// Function to set name of the pet.
string Pet::set_name() {
    string pet_name = "";
    cout << "Please enter the name of the pet: ";
    getline(cin, pet_name);
    return pet_name;
}

// Function to get type of the pet.
string Pet::get_type() {
    return type;
}

// Function to set type of the pet.
string Pet::set_type() {
    string pet_type = "";
    cout << "Please enter the type of the pet: ";
    getline(cin, pet_type);
    return pet_type;
}

// Function to get owner name of the pet.
string Pet::get_owner_name() {
    return owner_name;
}

// Function to set owner name of the pet.
string Pet::set_owner_name() {
    string pet_owner_name = "";
    cout << "Please enter the owner name of the pet: ";
    getline(cin, pet_owner_name);
    return pet_owner_name;
}


int main() {
    
    Pet pet1;
    pet1.initialize(pet1.set_name(), pet1.set_birth_year(), pet1.set_type(), pet1.set_owner_name());
    
    cout << pet1.get_birth_year() << endl;
    cout << pet1.get_name() << endl;
    cout << pet1.get_type() << endl;
    cout << pet1.get_owner_name() << endl;
    
    return 0;
}
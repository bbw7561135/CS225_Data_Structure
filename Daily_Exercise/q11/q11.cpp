#include <iostream>
#include <string>

class student {     // begin declaration of the class.
public:
    student(std::string itnName, int itnGrade); // Default constructor
    ~student();     // Default destructor
    
    int GetGrade() const;    // Accessor function
    std::string GetName() const;
    
private:
    std::string name;
    int grade;
};

student::student(std::string itnName, int itnGrade) {
    // Constructor of student.
    name = itnName;
    grade = itnGrade;
}

student::~student() {
    // Destructor of student.
}

int student::GetGrade() const {     // Get grade of the student
    return grade;
}

std::string student::GetName() const {      // Get name of the student
    return name;
}

void graduate(student &stu) {
    // Increase the grade by 1, pass the student object by reference.
    int x = stu.GetGrade();
    x++;
    std::cout << stu.GetName() << " is in grade " << x << "." << std::endl;
}

int main() {
    // Create an instance of the student class.
    student Stu("Sally", 5);
    std::cout << Stu.GetName() << " is in grade " << Stu.GetGrade() << "." << std::endl;
    graduate(Stu);
    
    return 0;
}
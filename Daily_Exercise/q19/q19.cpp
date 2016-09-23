#include <iostream>
#include <string>
using namespace std;

class Food{
    private:
        string name;
        int quantity;
    public:
        Food();
        void setName(string newName);
        void setQuantity(int newQuantity);
        string getName();
        int getQuantity() const;
};

Food::Food(){name = "food"; quantity = 0;}
void Food::setName(string newName){name = newName;}
void Food::setQuantity(int newQuantity){quantity = newQuantity;}
string Food::getName(){return name;}
int Food::getQuantity() const {return quantity;}

void increaseQuantity(Food * food){
    (*food).setQuantity((*food).getQuantity() + 1);
}


// Your `more` code here
// templated function.
template <class T>
T more(const T &food1, const T &food2) {
    if (food1.getQuantity() > food2.getQuantity()) return food1;
    else return food2;
}


int main(){
    Food apples, oranges, greater;
    apples.setName("apples");
    apples.setQuantity(8);
    oranges.setName("oranges");
    oranges.setQuantity(6);
    greater = more<Food>(apples, oranges);
    cout << "We have more " << greater.getName() << "." << endl;
    return 0;
}

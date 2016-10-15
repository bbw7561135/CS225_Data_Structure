#include <iostream>
using namespace std;

class Stack{
    private:
        struct node{
            int val;
            node * next;
        };
        node * head;
        int size;
    public:
        Stack();
        ~Stack();
        int getSize();
        bool isEmpty();
        void push(int value);
        int pop();
        void print();
};

// Default constructor
Stack::Stack() {
    head = NULL;
    size = 0;
}

// Destructor
Stack::~Stack() {
    node *temp = head;      // A temporary pointer starting from the head.
    while (temp != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

bool Stack::isEmpty() {
    if (size == 0)  return true;
    else    return false;
}

// Push function
void Stack::push(int value) {
    if (head == NULL) {
        node *temp = new node;
        temp->val = value;
        head = temp;
        temp->next = NULL;
    }
    else {
        node *temp = new node;
        temp->val = value;
        node *curr = head;
        head = temp;
        temp->next = curr;
    }
    size++;
}

void Stack::print() {
    node *temp = head;
    cout << "printing " << endl;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int Stack::getSize() {
    return size;
}

// Assumes the list is not empty.
int Stack::pop() {
    node *temp = head;
    head = head->next;
    int RetVal = temp->val;
    delete temp;
    return RetVal;
}


int main(){
    Stack a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << "popped " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();
    
    return 0;
}

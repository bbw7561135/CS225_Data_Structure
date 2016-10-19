#include <iostream>
using namespace std;

class Queue{
    private:
        struct node{
            int val;
            node * next;
        };
        node * head;
        node * tail;
        int size;
    public:
        Queue();
        ~Queue();
        int getSize();
        bool isEmpty();
        void push(int value);
        int pop();
        void print();
};

// Default constructor
Queue::Queue() {
    head = NULL;
    size = 0;
}

// Destructor
Queue::~Queue() {
    node *temp = head;      // A temporary pointer starting from the head.
    while (temp != NULL) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

bool Queue::isEmpty() {
    if (size == 0)  return true;
    else    return false;
}

void Queue::print() {
    node *temp = head;
    cout << "printing " << endl;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int Queue::getSize() {
    return size;
}

// Push function
void Queue::push(int value) {
    if (head == NULL) {
        node *temp = new node;
        temp->val = value;
        head = temp;
        tail = temp;
        temp->next = NULL;
    }
    else {
        node *temp = new node;
        temp->val = value;
        node *curr = tail;
        tail = temp;
        curr->next = tail;
        tail->next = NULL;
    }
    size++;
}

// Assumes the list is not empty.
int Queue::pop() {
    node *temp = head;
    head = head->next;
    int RetVal = temp->val;
    delete temp;
    return RetVal;
}


int main(){
    Queue a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << "popped " << a.pop() << endl;
    a.pop();
    a.pop();
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();
    
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

class word {
    public:
        word();         // Default constructor
        ~word();        // Destructor
        void remove_front();        // Remove the first node.
        void printList();           // Print the list.
        void insert_front(char c);        // Insert the first node.
        void invert();
        void insert_ay();           // Insert "ay" at the end of the word.
    private:
        char data;         // Characters
        word *head;     // Head pointer
        word *next;     // Next pointer
};

// Default constructor, to initialize the head pointer.
word::word() {
    head = NULL;
}

// Destructor
word::~word() {
    //cout << "Destructor called!" << endl;
    while (head != NULL) remove_front();
}

void word::remove_front() {
    word *h = head;     // Assign the h pointer pointing at the head.
    // If the deletion work has finished, and no more node in the heap.
    if (head == NULL) {
        cout << "Empty list." << endl;
        return;
    }
    head = head->next;      // Pointing to the next node.
    delete (h);
}

void word::printList()
{
    word *h = head;
    //cout << "Printing the list" << endl;
    while (h != NULL) {
        cout<< h->data;
        h = h->next;
    }
}

void word::insert_front(char c){
    word *temp = new word;
    temp->data = c;
    temp->next = NULL;
    if (head != NULL){
        temp->next = head;
    }
    head = temp;
}

void word::invert() {
    word *temp_h = head;        // Create a temp pointer pointing to the head.
    word *temp_t;        // Create another temp pointer pointing to the tail.
    
    while (temp_h != NULL) {
        temp_t = temp_h;
        temp_h = temp_h->next;
    }   // Now temp_t points at the tail of the list.
    
    temp_h = NULL;        // Discard this pointer to avoid wild pointer.
    
    temp_t->next = head;        // Point the last word to the first character.
    head = head->next;          // Now the head is put at the second character.
    temp_t->next->next = NULL;  // Point the "first" char to null
}

void word::insert_ay() {
    word *temp = head;
    word *newnode1 = new word;
    word *newnode2 = new word;
    char a = 'a';
    char y = 'y';
    newnode1->data = a;       // Create the new node.
    newnode1->next = newnode2;
    newnode2->data = y;
    newnode2->next = NULL;
    
    while (temp->next != NULL)
        temp = temp->next;
    
    temp->next = newnode1;
}

int main() {
    word Listword;
    string in_word, fc;
    int w_size = 0;         // Length of word.
    
    cout << "Input: ";
    cin >> in_word;
    w_size = in_word.size();
    
    // Enter "q" to quit.
    if (in_word == "q") {
        exit(1);
    }
    else {
        for (int i = w_size - 1; i >= 0; i--) {
            Listword.insert_front(in_word[i]);
        }
        
        // First char.
        fc = in_word[0];
        
        // For the words which start with consonants.
        if (w_size > 1 && fc != "a" && fc != "e" && fc != "i" && fc != "o" && fc != "u" && fc != "y")
            Listword.invert();
        
        Listword.insert_ay();
        
        cout << "output: ";
        Listword.printList();
        cout << endl;
        
    }
    
    return 0;
}
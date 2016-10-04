#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    if (head == NULL)   cout << "Empty list" << endl;
    
    int i = 0;
    while (head != NULL) {
        cout << "Node " << i << ": " << head->val << endl;
        head = head->next;
        i++;
    }
}

int main(){
    node * head = NULL;
    // enter code here to make a list...
    int arr[] = {1,2,3};
    int arr_size = sizeof(arr)/sizeof(*arr);
    
    for (int i = 0; i < arr_size; i++) {
        node *newNode = new node();
        newNode->val = arr[arr_size - 1 - i];
        newNode->next = head;   // The newNode is pointing to the "head"
        head = newNode;         // The first node is now newNode.
    }
    
    printList(head);
    
    return 0;
}

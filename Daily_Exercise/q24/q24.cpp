#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    node * temp = head;
    int count = 0;
    while(temp != NULL){
        cout << "Node " << count << ": " << temp ->val << endl;
        count++;
        temp = temp->next;
    }
}

void insertSorted(node ** head, node * insert){
    
    // your code here
    node *temp = *head;
    node *temp2;        // A pointer pointing to the head node.
    
    // If the list is empty.
    if (temp == NULL) {
        *head = insert;
        return;
    }
    
    // If the list is not empty.
    while(temp != NULL) {
        // If the insert node is smaller than the other nodes.
        if (temp->val >= insert->val) {
            insert->next = *head;
            *head = insert;
            return;
        }
        // If the inserted node is in the middle.
        else if (temp->val < insert->val && temp->next->val >= insert->val) {
            temp2 = temp->next;
            temp->next = insert;
            insert->next = temp2;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        temp->next = insert;
        return;
    }
}


int main(){

    // put test cases here
    node * head = NULL;
    int arr[] = {1,2,3,5};
    int arr_size = sizeof(arr)/sizeof(*arr);
    
    node *newNode = new node[arr_size];
    
    for (int i = 0; i < arr_size; i++) {
        newNode[i].val = arr[arr_size - 1 - i];
        newNode[i].next = head;   // The newNode is pointing to the "head"
        head = &newNode[i];         // The first node is now newNode.
    }
    
    // New node to be inserted
    int insertarr = 4;      // Value of the node to be inserted.
    node *insertNode = new node();
    
    insertNode->next = NULL;
    insertNode->val = insertarr;
    
    insertSorted(&head, insertNode);
    printList(head);
    
    delete []newNode;
    delete insertNode;

    return 0;
}

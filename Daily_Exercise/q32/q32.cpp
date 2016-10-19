#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
}

node *createList(int arr[], int size){
    node * ret = new node;
    ret->val = arr[0];
    node * temp = ret;
    for(int i = 1; i < size; i ++){
        temp->next = new node;
        temp = temp->next;
        temp->val = arr[i];
    }
    temp->next = NULL;
    return ret;
}

node *requeue(node **head, int times) {
    node *temp1 = *head;
    
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    
    // Go to the last element of the queue, and assign temp2 pointer pointing to it.
    node *temp2 = temp1;
    temp1 = *head;
    
    for (int i = 0; i < times; i++) {
        *head = (*head)->next;      // Setting the position of the new new head.
        temp2->next = temp1;        // Put the element to the tail.
        temp1->next = NULL;
        temp2 = temp1;              // Assign the tail to the newly added element.
        temp1 = *head;              // Assign temp1 pointer pointing to the head.
    }
    
    return *head;
}


int main(){
    int arr[5] = {1,2,3,4,5};
    node * n = createList(arr, 5);
    printList(n);
    cout << endl;
    requeue(&n, 3);
    cout << endl;
    printList(n);
    cout << endl;
    return 0;
}

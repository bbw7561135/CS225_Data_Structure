#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void Splittwolist(node *headRef, node **frontRef, node **backRef);
node *SortedMerge(node *a, node *b);

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
    node * temp = *head;
    if(temp == NULL){
        *head = insert;
        insert->next = NULL;
        return;
    }
    if(temp->val >= insert->val){   // this node becomes the new head
        insert->next = temp;
        *head = insert;
    }
    else{
        node * prev = *head;
        temp = temp->next;
        while(temp != NULL){
            if(temp->val >= insert->val){
                insert->next = temp;
                prev->next = insert;
                return;
            }
            temp = temp->next;
            prev = prev->next;
        }
        // we reached the end of list, this node must go at the end
        // prev points to last node, temp points to NULL
        prev->next = insert;
        insert->next = NULL;
    }
}

// Write a sortlist method here.
// Using Merge Sort method
void MergeSort(node **headRef) {
    node *head = *headRef;
    node *a;
    node *b;
    
    // Base case, if the length is 0 or 1.
    if ((head == NULL) || (head->next == NULL)) return;
    
    // Split into two sublists.
    Splittwolist(head, &a, &b);
    
    // Recursively sort the lists.
    MergeSort(&a);
    MergeSort(&b);
    
    *headRef = SortedMerge(a,b);
}

// Merge two lists together.
node *SortedMerge(node *a, node *b) {
    node *mergesort = NULL;
    
    // Base cases.
    if (a == NULL)  return b;
    else if (b == NULL) return a;
    
    if (a->val <= b->val) {
        mergesort = a;      // Pick one element from a.
        mergesort->next = SortedMerge(a->next, b);
    }
    else {
        mergesort = b;      // Pick one element from b.
        mergesort->next = SortedMerge(a, b->next);
    }
    
    return mergesort;
}

// Split two sub-lists.
void Splittwolist(node *headRef, node **frontRef, node **backRef) {
    node *fast;
    node *slow;
    
    // Base case, length < 2 cases.
    if (headRef == NULL || headRef->next == NULL) {
        *frontRef = headRef;
        *backRef = NULL;
    }
    
    else {
        slow = headRef;
        fast = headRef->next;
        
        // Advance fast by two nodes, and slow by one node, so fast would point to the end of the list, while slow would point to one node in front of the middle of the list.
        while (fast != NULL) {
            fast = fast->next;
            // Not yet end, taking the case when length is even. This part is not executed if length is odd.
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        *frontRef = headRef;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

int main(){

    // write test cases here.
    node *head = NULL;
    int arr[] = {9,10,3,6,1,7,100,54};
    int arr_size = sizeof(arr)/sizeof(*arr);
    
    node *newNode = new node[arr_size];
    
    for (int i = 0; i < arr_size; i++) {
        newNode[i].val = arr[arr_size - 1 - i];
        newNode[i].next = head;     // The newNode is pointing to the "head"
        head = &newNode[i];         // The first node is now newNode.
    }
    
    MergeSort(&head);
    
    printList(head);
    
    delete []newNode;

    return 0;
}

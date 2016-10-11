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

void sortList(node ** head){
    node * newHead = NULL;
    node * curHead = *head;
    node * insert;
    while(curHead != NULL){
        insert = curHead;
        curHead = curHead->next;
        insert->next = NULL;
        insertSorted(&newHead, insert);
    }
    *head = newHead;
}

node * shuffle(node * a, node * b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    node * aptr = a;
    node * bptr = b;
    while(aptr->next != NULL && bptr->next != NULL){
        node * tempa = aptr;
        aptr = aptr->next;
        node * tempb = bptr;
        bptr = bptr->next;
        tempa->next = tempb;
        tempb->next = aptr;
    }
    if(aptr->next == NULL){ // tack on rest of b
        aptr->next = bptr;
    }
    else{   // bptr->next == NULL
        // add last b node to a list
        node * tempa = aptr;
        aptr = aptr->next;
        tempa->next = bptr;
        bptr->next = aptr;
    }
    return a;
}

int rep_int = -999999;      // Global variable to check repetitive integers.

node * intersection(node * a, node * b) {
    // Return empty intersection list if one of them were null.
    if (a == NULL || b == NULL)  return NULL;
    
    // First sort the two lists that are to be compared.
    sortList(&a);
    sortList(&b);
    
    // Advance the smaller list and call recursively.
    if (a->val < b->val)    return intersection(a->next, b);
    if (a->val > b->val)    return intersection(a, b->next);
    
    // Getting rid of the repetitive elements.
    if (a->val != rep_int) {
        // If a->val == b->val, then:
        node *inter_list = new node();
    
        inter_list->val = a->val;
        rep_int = a->val;
        inter_list->next = intersection(a->next, b->next);
        return inter_list;
    }
    
    else    return intersection(a->next, b->next);
}

int main(){

    // put tests here
    node *head_a = NULL;
    node *head_b = NULL;
    int a[] = {5,9,0,3,0};
    int b[] = {3,5,6,7,0,0};
    int a_size = sizeof(a)/sizeof(*a);
    int b_size = sizeof(b)/sizeof(*b);
    
    node *newNode_a = new node[a_size];
    node *newNode_b = new node[b_size];
    
    for (int i = 0; i < a_size; i++) {
        newNode_a[i].val = a[a_size - 1 - i];
        newNode_a[i].next = head_a;     // The newNode is pointing to the "head"
        head_a = &newNode_a[i];         // The first node is now newNode.
    }
    for (int i = 0; i < b_size; i++) {
        newNode_b[i].val = b[b_size - 1 - i];
        newNode_b[i].next = head_b;     // The newNode is pointing to the "head"
        head_b = &newNode_b[i];         // The first node is now newNode.
    }
    
    node *inter_list = NULL;
    inter_list = intersection(head_a, head_b);
    
    printList(inter_list);
    
    delete []newNode_a;
    delete []newNode_b;

    return 0;
}

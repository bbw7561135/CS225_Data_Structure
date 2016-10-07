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
    // Base case.
    if (a == NULL) return b;
    if (b == NULL) return a;
    
    node *temp1 = shuffle(a->next, b->next);    // See what are the last elements
    node *temp2 = a;
    
    temp2->next = b;
    b->next = temp1;
    return temp2;
}

int main(){
    node *head_a = NULL;
    node *head_b = NULL;
    int a[] = {0,2};
    int b[] = {1,3,3,4};
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

    
    node *shuf_list = NULL;
    shuf_list = shuffle(head_a, head_b);
    
    printList(shuf_list);
    
    delete []newNode_a;
    delete []newNode_b;

    return 0;
}

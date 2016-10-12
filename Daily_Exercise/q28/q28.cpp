#include <iostream>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
};

void printTree(node * root){
    if(root == NULL){
        cout << "NULL ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

void smoosh(node * root){
   // Your code here!
    if (root == NULL) return;
    while (root) {
        if (root->left) {
            node *pre = root->left;
            while (pre->right)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}


int main(){
    node * root = new node;
    root->val = 1;
    node * temp = root;
    temp->left = new node;
    temp->left->val = 2;
    temp = temp->left;
    temp->left = new node;
    temp->left->val = 3;
    temp->left->left = NULL;
    temp->left->right = NULL;
    temp->right = new node;
    temp->right->val = 4;
    temp->right->left = NULL;
    temp->right->right = NULL;
    temp = root;
    temp->right = new node;
    temp->right->val = 5;
    temp->right->left = NULL;
    temp = temp->right;
    temp->right = new node;
    temp->right->val = 6;
    temp->right->left = NULL;
    temp->right->right = NULL;
    printTree(root);
    cout << endl;
    smoosh(root);
    printTree(root);
    return 0;
}

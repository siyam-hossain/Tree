#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node *left;
    node *right;

    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(node *root)
{

    //left root right
    if(root==NULL) return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
    
}

int main(int argc, char const *argv[])
{

    //10 20 30 40 50 60
    /*
            10
          20  

    */
    node *root = new node(10);   
    node *a = new node(20);   
    node *b = new node(30);   
    node *c = new node(40);   
    node *d = new node(50);   
    node *e = new node(60);

    root->left = a;
    root->right = b;

    a->left = c;
    a->right = d;

    b->left = e;

    inorder(root);

    return 0;
}
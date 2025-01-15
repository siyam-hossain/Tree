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

void level_order(node *root)
{

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        node *front = q.front();
        q.pop();

        // 2. oi node ke niye kaj
        cout<<front->val<<" ";

        // 3. push children 
        if(front->left) q.push(front->left);//jodi front->left != NULL taile push
        if(front->right) q.push(front->right);//joid front->right != NULL taile push
    }
}

int main(int argc, char const *argv[])
{

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

    level_order(root);

    return 0;
}
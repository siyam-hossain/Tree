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

node *input_tree()
{
    int data;
    cin>>data;
    node *root = new node(data);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

       node *f = q.front();
       q.pop();



        node *lchild, *rchild;
        int lft, rgt;
        cin>>lft>>rgt;

        (lft == -1) ? lchild = NULL : lchild = new node(lft);
        (rgt == -1) ? rchild = NULL : rchild = new node(rgt);
            f->left = lchild;
            f->right = rchild;


        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);

    }
    
    return root;
};

bool search(node *root, int val)
{
    if(root == NULL) return false;
    if(root->val == val) return true;

    //recursion
    return (root->val > val) ? search(root->left, val) :search(root->right, val);
    //or
    // if(root->val > val) return search(root->left,val); //O(logh)
    // if(root->val < val) return search(root->right,val);//O(logh)
}


int main(int argc, char const *argv[])
{

    /*
        Inputs: 18 7 21 -1 12 20 26 9 15 -1 -1 -1 -1 -1 -1 -1 -1
                150
    */
    node *root = input_tree();
    
    int val;
    cin>>val;
    
    cout<<((search(root,val)) ? "Found" : "Not found");

    return 0;
}
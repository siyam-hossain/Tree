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

int max_height(node *root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 0;

    int lft = max_height(root->left);
    int rgt = max_height(root->right);

    return max(lft , rgt) + 1;
}

int main(int argc, char const *argv[])
{

    //input: 6 3 5 -1 2 0 -1 -1 1 -1 -1 -1 -1 
    //output: 3
    node *root = input_tree();
    
    cout<<max_height(root);
    
    return 0;
}
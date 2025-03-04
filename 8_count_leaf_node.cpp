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

int cnt_leaf_nodes(node *root)
{
    if(root == NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;

    int lft = cnt_leaf_nodes(root->left);
    int rgt = cnt_leaf_nodes(root->right);

    return lft+rgt;
}

int main(int argc, char const *argv[])
{
    node *root = input_tree();
    
    cout<<cnt_leaf_nodes(root);
    return 0;
}
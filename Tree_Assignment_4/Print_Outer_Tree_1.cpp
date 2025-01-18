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

void left_print(node* root)
{
    if(root == NULL) return;
    if(root->left)
    {
        left_print(root->left);
    }
    else if(root->right)
    {
        left_print(root->right);
    }
    cout<<root->val<<" ";
}
void right_print(node* root)
{
    if(root == NULL) return;
    cout<<root->val<<" ";

    if(root->right)
    {
        right_print(root->right);
    }
    else if(root->left)
    {
        right_print(root->left);
    }
}

int main(int argc, char const *argv[])
{

    node *root = input_tree();
    if(root == NULL) return 0;
    if(root->left)
    {
        left_print(root);
    }
    if(root->right)
    {
        if(root->left == NULL) cout<<root->val<<" ";
        right_print(root->right);
    }

    return 0;
}
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

int sum;

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




int sum_wo_ln(node *root)
{
    if(root == NULL) return 0;
    if(root->left != NULL  || root->right != NULL)
    {

        sum = sum + root->val;
    
        sum_wo_ln(root->left);
        sum_wo_ln(root->right);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    sum = 0;

    node *root = input_tree();

    cout<<sum_wo_ln(root);
    return 0;
}
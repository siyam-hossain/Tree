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


void level_order(node *root)
{

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        cout<<front->val<<" ";

        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

void insert(node *&root, int val)//it require reference 
{
    if(root == NULL)
    {
        //due to root update
        root = new node(val);
    }

    if(root->val > val)
    {
        if(root->left == NULL) root->left = new node(val);
        else insert(root->left,val); //calling recursion
    }
    else
    {
        if(root->right == NULL ) root->right = new node(val);
        else insert(root->right,val); //calling recursion
    }
}


int main(int argc, char const *argv[])
{
   
    node *root = input_tree();
    int val;
    cin>>val;
    
    insert(root,val);
    insert(root,11);
    level_order(root);

    return 0;
}
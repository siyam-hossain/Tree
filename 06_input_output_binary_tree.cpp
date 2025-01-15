/*
    1. level order input
    2. NUll node assign with -1
    
                        1
                2             3
            0       -1    -1      5 


    3. inputs: 10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1

*/
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
        /*
            1. ber kore ana
            2. oi node niye kaj
            3. oi node er childern push
        */

       //1.
       node *f = q.front();
       q.pop();



        // 2.
        node *lchild, *rchild;
        int lft, rgt;
        cin>>lft>>rgt;

        (lft == -1) ? lchild = NULL : lchild = new node(lft);
        (rgt == -1) ? rchild = NULL : rchild = new node(rgt);
            //now add connections
            f->left = lchild;
            f->right = rchild;


        //3.
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);

    }
    
    return root;
};


//tree printing
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
    node *r_root = input_tree();
    level_order(r_root);
    return 0;
}
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

vector<int> res;

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

void left_sub(node* root)
{
    int fca[10005] = {false};//acording to the constrain
    queue<pair <node *, int> > trq;

    if(root) trq.push({root, 0});

    while (!trq.empty())
    {
        pair<node *, int> pr = trq.front();
        trq.pop();

        node *parent = pr.first;
        int lvl = pr.second;

        if(fca[lvl] == false)
        {
            res.push_back(parent->val);
            fca[lvl] = true;
        }

        if(parent->left) trq.push({parent->left, lvl+1});
        else if(parent->right) trq.push({parent->right, lvl+1});
    }
}

void right_sub(node* root)
{
    int fca[10005] = {false};//acording to the constrain
    queue<pair <node *, int> > trq;

    if(root) trq.push({root, 0});

    while (!trq.empty())
    {
        pair<node *, int> pr = trq.front();
        trq.pop();

        node *parent = pr.first;
        int lvl = pr.second;

        if(fca[lvl] == false)
        {
            res.push_back(parent->val);
            fca[lvl] = true;
        }

        if(parent->right) trq.push({parent->right, lvl+1});
        else if(parent->left) trq.push({parent->left, lvl+1});
    }
}




int main(int argc, char const *argv[])
{

    node *root = input_tree();
    
    //traversing left sub
    if(root->left) left_sub(root->left);
    //assigning value in vector
    //reverse that vector
    reverse(res.begin(),res.end());
    
    //executing a edge case
    //we have to push root value on to the vector
    res.push_back(root->val);
    
    //traversing right sub
    if(root->right) right_sub(root->right);
    //this don't require to reverse

    //now i can print the output from the vector
    for (auto i : res)
    {
        cout<<i<<" ";
    }cout<<endl;
    

    
    return 0;
}
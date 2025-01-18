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

vector<int> leaf_child;

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


void des_or_lfn(node *root)
{

    if(root == NULL) return;
    if(root->left == NULL  && root->right == NULL) 
    {
        leaf_child.push_back(root->val);
    }
    
    des_or_lfn(root->left);
    des_or_lfn(root->right);
}

int main(int argc, char const *argv[])
{
    node *root = input_tree();

    des_or_lfn(root);
    // reverse(leaf_child.begin(),leaf_child.end());
    sort(leaf_child.begin(),leaf_child.end(),greater<>());

    for (auto i : leaf_child)
    {
        cout<<i<<" ";
    }cout<<endl;
    
    return 0;
}
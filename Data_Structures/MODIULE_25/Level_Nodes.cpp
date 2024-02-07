#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root == NULL;
    }
    else
    {
        root = new Node(val);
    }
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1;
        Node *f = q.front();
        q.pop();

        // 2
        int l, r;
        cin >> l >> r;
        Node *left;
        Node *right;
        if (l == -1)
            left = NULL;
        else
            left = new Node(l);
        if (r == -1)
            right = NULL;
        else
            right = new Node(r);

        f->left = left;
        f->right = right;

        // 3
        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
    return root;
}

void level_Nodes(Node* root, int level){
    if(!root||level<0){
        cout<<"Invalid"<<endl;
        return;
    }
    queue<pair<Node*,int>>q;
    q.push({root,0});
    bool found = false;

    while(!q.empty()){
        Node*node=q.front().first;
        int nodeLevel=q.front().second;
        q.pop();

        if(nodeLevel==level){
            found=true;
            cout<<node->val<<" ";
        }

        if(node->left) q.push({node->left,nodeLevel+1});
        if(node->right) q.push({node->right,nodeLevel+1});
    }

    if(!found){
        cout<<"Invalid"<<endl;
    }
}

int main()
{
    Node *root = input_tree();
    int level;
    cin>>level;
    level_Nodes(root,level);
    return 0;
}


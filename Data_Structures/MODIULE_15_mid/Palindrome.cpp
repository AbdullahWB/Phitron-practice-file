#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    };
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

bool palindrome(Node*head,Node*tail){
    Node*i=head;
    Node*j=tail;
    bool flag=true;

    while(i!=j){
        if(i->val!=j->val){
            flag=false;
            break;
        }
        i=i->next;
        j=j->prev;
    }
    return flag;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    while(true){
        cin>>val;
        if(val==-1){
            break;
        }
        insert_at_tail(head,tail,val);
    }

    if(palindrome(head,tail)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    };
};

void print_linked_list(Node* head){
    Node *tmp = head;
    while(tmp != NULL){
        cout<< tmp->val << endl;
        tmp = tmp->next;
    }
};

int size(Node* head){
    Node *tmp = head;
    int count = 0;
    while(tmp != NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
};

void insert(Node* head, int val, int pos){
    Node *newNode = new Node(val);
    Node *tmp = head;
    for(int i=1; i<=pos-1; i++){
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;
};

void insert_head(Node*& head, int val){
    Node *newNode = new Node(val);
    newNode->next=head;
    head=newNode;
}

int main()
{
    Node * head = new Node(10);  
    Node * a = new Node(20);  
    Node * b = new Node(30);  
    Node * c = new Node(40);  
    Node * d = new Node(50);

    head->next=a;
    a->next=b;
    b->next=c;  
    c->next=d;

    int pos,val;
    cin>>pos>>val;
    if(pos>size(head)){
        cout<<"Invalid Index"<< endl;
    }else if (pos==0)
    {
        insert_head(head, val);
    }else{
        insert(head,val,pos);
    }
    print_linked_list(head);

    return 0;
}
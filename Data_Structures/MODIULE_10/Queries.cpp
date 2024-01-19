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

void insert_at_head(Node*&head,int val){
    Node*newNode=new Node(val);
    newNode->next=head;
    head=newNode;
}

void insert_tail(Node *&head, int val){
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void delete_node(Node*&head,int pos){
    if(head==NULL){
        return;
    }
    if(pos==0){
        Node *deleteNode=head;
        head=head->next;
        delete deleteNode;
        return;
    }
    Node *tmp= head;
    int count=0;

    while(count<pos-1 && tmp!=NULL){
        tmp=tmp->next;
        count++;
    }
    if(tmp==NULL || tmp->next==NULL){
        return;
    }
    Node *deleteNode = tmp->next;
    tmp->next=tmp->next->next;
    delete deleteNode;
}


int size(Node *head)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
};

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout<<endl;
};

int main()
{
    int q;
    cin>>q;
    Node *head=NULL;

    for(int i=0;i<q; i++){
        int x,v;
        cin>>x>>v;
        if(x==0){
            insert_at_head(head,v);
        }else if(x==1){
            insert_tail(head, v);
        }else if(x==2){
            int node_size=size(head);
            if(v>=0&&v<node_size){
                delete_node(head,v);
            }
        }
        print_linked_list(head);
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     };
// };

// void insert_at_head(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
//     newNode->next = head;
//     head = newNode;
// }

// int size(Node *head)
// {
//     Node *tmp = head;
//     int count = 0;
//     while (tmp != NULL)
//     {
//         count++;
//         tmp = tmp->next;
//     }
//     return count;
// };

// void insert_at_tail(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
//     if (head == NULL)
//     {
//         head = newNode;
//         return;
//     }

//     Node *temp = head;
//     while (temp->next != NULL)
//     {
//         temp = temp->next;
//     }
//     temp->next = newNode;
// }

// void delete_at_index(Node *&head, int index)
// {
//     if (head == NULL)
//     {
//         return;
//     }

//     if (index == 0)
//     {
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }

//     Node *temp = head;
//     int count = 0;

//     while (count < index - 1 && temp != NULL)
//     {
//         temp = temp->next;
//         count++;
//     }

//     if (temp == NULL || temp->next == NULL)
//     {
//         return; // Invalid index
//     }

//     Node *deleteNode = temp->next;
//     temp->next = temp->next->next;
//     delete deleteNode;
// }

// void print_linked_list(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     int q;
//     cin >> q;

//     Node *head = NULL;
//     // Node *tail = NULL;

//     for (int i = 0; i < q; i++)
//     {
//         int x, v;
//         cin >> x >> v;

//         if (x == 0)
//         {
//             insert_at_head(head, v);
//         }
//         else if (x == 1)
//         {
//             insert_at_tail(head, v);
//         }
//         else if (x == 2)
//         {
//             int list_size = size(head);
//             if (v >= 0 && v < list_size)
//             {
//                 delete_at_index(head, v);
//             }
//         }

//         print_linked_list(head);
//     }

//     return 0;
// }

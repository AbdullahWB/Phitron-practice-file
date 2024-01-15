#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    };
};

void insert_at_tail(Node *&head, int v) // in Link List Just have head so in function parameter is head like (Node* head) and insert a new head you must have give a new val like (int v).
{
    Node *newNode = new Node(v); // create new node by dynamic allocation node object.

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head; // we never moved or changed head so we need to insert head value in tmp.

    while (tmp->next != NULL)
    {                    // if tem->next is NULL
        tmp = tmp->next; // tmp is now in last Node position.
    }
    tmp->next = newNode; // tmp is now in last Node position and insert a new node value in tmp
    cout << endl
         << "Inserted at Tail" << endl
         << endl;
}

void print_linked_list(Node *head)
{
    cout << endl;
    cout << "Your linked list is:"
         << " ";
    Node *tmp = head;
    while (tmp != NULL)
    {                            // this loop will be brack when tmp is NULL.
        cout << tmp->val << " "; // print tmp value
        tmp = tmp->next;         // and set tmp in next Node position
    }
    cout << endl
         << endl;
}

void insert_at_position(Node *head, int pos, int v)
{
    Node *newNode = new Node(v);
    Node *tmp= head;
    for(int i=1; i<pos-1; i++){
        tmp=tmp->next;
    }
}

int main()
{
    Node *head = NULL; // at first creat Node pointer which will be drive value NULL.

    while (true)
    {
        // start insertion process number 1 to step inserting number of nodes 1 (op==1).
        cout << "Option 1: Inserting a Tail value" << endl;
        cout << "Option 2: Print Link List" << endl;
        cout << "Option 3: Insert at any position" << endl;
        cout << "Option 4: Terminate" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Please enter the Value to insert: " << endl;
            int v;
            cin >> v;
            insert_at_tail(head, v); // provide head and new Node value
        }
        // end insertion process number 1 to step inserting number of nodes
        else if (op == 2)
        {
            print_linked_list(head); // to provide head Node data in this function.
        }
        else if (op == 3)
        {
            int pos, v;
            cout << "Enter Position: ";
            cin >> pos;
            cout << "Enter Value: ";
            cin >> v;
        }
        else if (op == 4)
        {
            break;
        }
    }

    return 0;
}
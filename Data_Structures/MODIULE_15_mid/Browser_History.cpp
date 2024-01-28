#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string address;
    Node *prev;
    Node *next;
    Node(string address)
    {
        this->address = address;
        this->prev = NULL;
        this->next = NULL;
    };
};

void insert_at_tail(Node *&head, Node *&tail, string address)
{
    Node *newNode = new Node(address);
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

void print(Node *node)
{
    if (node != NULL)
    {
        cout << node->address << endl;
    }
    else
    {
        cout << "Not Available" << endl;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string address;

    while (true)
    {
        cin >> address;
        if (address == "end")
        {
            break;
        }
        insert_at_tail(head, tail, address);
    }

    int q;
    cin >> q;

    string commend, newAddress;
    cin >> commend >> newAddress;

    Node *cur = head;

    while (cur != NULL && cur->address != newAddress)
    {
        cur = cur->next;
    }

    print(cur);

    for (int i = 1; i < q; ++i)
    {
        cin >> commend;
        if (commend == "visit")
        {
            cin >> newAddress;
            Node *tmp = head;
            while (tmp != NULL && tmp->address != newAddress)
            {
                tmp = tmp->next;
            }
            if (tmp != NULL)
            {
                cur = tmp;
                print(cur);
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (commend == "next")
        {
            if (cur->next != NULL)
            {
                cur = cur->next;
                print(cur);
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (commend == "prev")
        {
            if (cur->prev != NULL)
            {
                cur = cur->prev;
                print(cur);
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }
    return 0;
}
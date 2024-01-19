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

void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
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

bool list_equal(Node *head1, Node *head2)
{
    int size1 = size(head1);
    int size2 = size(head2);

    if (size1 != size2)
    {
        return false;
    }

    Node *tmp1 = head1;
    Node *tmp2 = head2;

    while (tmp1 != NULL)
    {
        if (tmp1->val != tmp2->val)
        {
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return true;
}

int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Node *tail = NULL;

    int val;

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail(head1, tail, val);
    }

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail(head2, tail, val);
    }

    if (list_equal(head1, head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
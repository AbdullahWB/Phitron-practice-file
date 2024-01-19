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

void delete_duplicate(Node *node)
{
    if (!node || !node->next)
    {
        return;
    }
    unordered_set<int> seen_values;
    Node *current = node;

    while (current->next)
    {
        seen_values.insert(current->val);
        while (current->next && seen_values.count(current->next->val))
        {
            Node *next_node = current->next;
            current->next = next_node->next;
            delete next_node;
        }
        if (current->next)
        {
            current = current->next;
        }
    }
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
};

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_tail(head, tail, val);
    }

    Node *current = head;
    while (current)
    {
        delete_duplicate(current);
        current = current->next;
    }
    print_linked_list(head);
    return 0;
}
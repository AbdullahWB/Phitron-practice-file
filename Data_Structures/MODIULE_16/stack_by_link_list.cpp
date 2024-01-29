#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *pre;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->pre = NULL;
        this->next = NULL;
    };
};

class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->pre=tail;
        tail->next = newNode;
        tail = tail->next;
    }
    void pop()
    {
        sz--;
        Node *deleteNode = tail;
        tail = tail->pre;
        if (tail == NULL)
        {
            head = NULL;
        }else{
            tail->next = NULL;
        }
        delete deleteNode;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        if (sz == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    myStack st;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    while (!st.isEmpty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
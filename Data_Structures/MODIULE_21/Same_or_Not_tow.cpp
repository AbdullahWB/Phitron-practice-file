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
        newNode->pre = tail;
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
        }
        else
        {
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
    bool empty()
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

class myQueue
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
        }
        tail->next = newNode;
        newNode->pre = tail;
        tail = tail->next;
    }

    void pop()
    {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->pre = NULL;
        delete deleteNode;
    }

    int front()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};

int main()
{
    myStack st;
    myQueue q;

    int n, m;
    cin >> n >> m;

    if (n != m)
    {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    for (int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        q.push(y);
    }

    bool flag = true;

    while (!st.empty())
    {
        if (st.top() != q.front())
        {
            flag = false;
            break;
            ;
        }
        st.pop();
        q.pop();
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
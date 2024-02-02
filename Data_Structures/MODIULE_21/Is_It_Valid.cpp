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

string isValid(string s){
    myStack st;

    for(char c:s){
        if(!st.empty() && st.top()== '0' && c=='1'){
            st.pop();
        }else if(!st.empty() && st.top()=='1'&&c=='0'){
            st.pop();
        }else{
            st.push(c);
        }
    }

    return (st.empty() ? "YES" : "NO");
};

int main()
{
    int n;
    cin >> n;

    while(n--){
        string s;
        cin >> s;
        cout<<isValid(s)<<endl;
    }

    return 0;
}
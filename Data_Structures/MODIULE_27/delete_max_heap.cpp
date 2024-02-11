#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int x)
{
    v.push_back(x);
    int current = v.size() - 1;
    while (current != 0)
    {
        int part = (current - 1) / 2;
        if (v[current] > v[part])
            swap(v[current], v[part]);
        else
            break;
        current = part;
    }
}

void delete_heap(vector<int> &v)
{
    v[0] = v[v.size() - 1];
    v.pop_back();
    int curr = 0;
    while (true)
    {
        int left_ind = curr * 2 + 1;
        int right_ind = curr * 2 + 2;
        int last_ind = v.size() - 1;
        if (left_ind <= last_ind && right_ind <= last_ind)
        {
            if (v[left_ind] >= v[right_ind] && v[left_ind] > v[curr])
            {
                swap(v[left_ind], v[curr]);
                curr = left_ind;
            }
            else if (v[right_ind] >= v[left_ind] && v[right_ind] > v[last_ind])
            {
                swap(v[right_ind], v[last_ind]);
                curr = right_ind;
            }
            else
            {
                break;
            }
        }
        else if (left_ind <= last_ind)
        {
            if (v[left_ind] > v[last_ind])
            {
                swap(v[left_ind], v[last_ind]);
                curr = left_ind;
            }
            else
            {
                break;
            }
        }
        else if (right_ind <= last_ind)
        {
            if (v[right_ind] > v[last_ind])
            {
                swap(v[right_ind], v[last_ind]);
                curr = right_ind;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void print_heap(vector<int>v){
    for(int val:v){
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_heap(v, x);
    }
    print_heap(v);
    delete_heap(v);
    print_heap(v);
    delete_heap(v);
    print_heap(v);
    // print_heap(v);
    delete_heap(v);
    print_heap(v);
    delete_heap(v);
    print_heap(v);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        int current = v.size()-1;
        while(current !=0){
            int part = (current-1)/2;
            if(v[current]>v[part]) swap(v[current],v[part]);
            else break;
            current = part;
        }
    }
    for(int val:v){
        cout << val << " ";
    }
    return 0;
}
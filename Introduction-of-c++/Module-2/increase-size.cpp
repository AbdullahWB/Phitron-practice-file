#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }   
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    delete[] a;

    a=new int[5];

    for (int i = 0; i < n; i++)
        a[i] = b[i];
    
    delete[] b;
    a[3]=40;
    a[4]=50;

    for(int i = 0; i < 5; i++){
        cout << a[i] << " ";
    }

    return 0;
}
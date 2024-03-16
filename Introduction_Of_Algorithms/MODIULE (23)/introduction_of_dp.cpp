#include <bits/stdc++.h>
using namespace std;

void print_number(int n){
    if(n>=11) return;
    cout<<n<<endl;
    print_number(n+1);
}

int main()
{
    print_number(1);
    return 0;
}
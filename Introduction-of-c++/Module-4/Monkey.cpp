#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s[100005];
    while(cin.getline(s, 100005)){
        sort(s, s+strlen(s));
        long long int len = strlen(s);
        for(int i = 0; i <len; i++){
            if(s[i]!=' '){
                cout<<s[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
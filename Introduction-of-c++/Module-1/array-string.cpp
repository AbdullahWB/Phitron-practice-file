#include <iostream>
#include <string>
using namespace std;

int main(){
    char s[100];
    cin>>s;
    // fgets(s, 100, stdin);
    cin.getline(s, 100);
    cout<<s<<endl;
    
    return 0;
}
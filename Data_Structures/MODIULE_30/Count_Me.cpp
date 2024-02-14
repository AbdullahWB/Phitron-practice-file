#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        map<string,int>mp;
        string sentence;
        getline(cin, sentence);
        string word;
        stringstream ss(sentence);
        string ans;
        int mx = 0;
        while(ss >> word){
            mp[word]++;
            if(mp[word]>mx){
                mx = mp[word];
                ans=word;
            }
        }
        cout<<ans<< " "<<mx<<endl;
    }
    return 0;
}
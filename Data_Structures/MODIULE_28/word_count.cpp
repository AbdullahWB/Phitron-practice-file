#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int>mp;
    string sentence;
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    while(ss>>word){
        // cout << word << endl;
        mp[word]++;
    }
    for(auto it=mp.begin(); it!=mp.end(); it++){
        cout<<it->first << " " << it->second << endl;
    }
    cout<<mp["Love"] << endl;
    return 0;
}

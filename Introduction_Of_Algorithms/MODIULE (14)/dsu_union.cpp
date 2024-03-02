#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int union_size[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        union_size[i]=1;
    }
}

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2){
    int leaderA=find(node1);
    int leaderB=find(node2);
    par[leaderA] = leaderB;
}

void dsu_union_by_size(int node1,int node2){
    int leaderA=find(node1);
    int leaderB=find(node2);
    if(union_size[leaderA]>union_size[leaderB]){
        par[leaderB]=leaderA;
        union_size[leaderA]+=union_size[leaderB];
    }else{
        par[leaderA]=leaderB;
        union_size[leaderB]+=union_size[leaderA];
    }
}

int main()
{
    dsu_initialize(8);
    dsu_union_by_size(1,2);
    dsu_union_by_size(2,3);
    dsu_union_by_size(4,5);
    dsu_union_by_size(5,6);
    cout<<find(1)<<endl;
    cout<<find(4)<<endl;
    return 0;
}
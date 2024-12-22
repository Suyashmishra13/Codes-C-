#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,char>> graph[n+1];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        char x;
        cin>>x;
        graph[a].push_back({b,x});
        graph[b].push_back({a,x});
    }
    // ya yb yb yc ya yc yb ya
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin>>n>>m;
    vector<long long> graph[n];
    vector<long long> back[n];
    vector<long long> indeg(n,0);
    while(m--){
        long long a,b;
        cin>>a>>b;
        graph[--a].push_back(--b);
        back[b].push_back(a);
        indeg[b]++;
    }
    queue<long long> topol;
    for(long long i=0; i<n; i++){
        if(!indeg[i]) topol.push(i);
    }
    vector<long long> order;
    while(!topol.empty()){
        long long cur = topol.front();
        topol.pop();
        order.push_back(cur);
        for(long long x : graph[cur]){
            if(--indeg[x] == 0){
                topol.push(x);
            }
        }
    }
    vector<long long> ways(n,0);
    ways[0] = 1;
    for(long long x : order){
        long long cur = x;
        long long m = 0;
        for(long long y : back[cur]){
            m+=ways[y];
        }
        ways[cur] += m;
        ways[cur]%=mod;
    }
    cout<<ways[n-1];
    return 0;
}
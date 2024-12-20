#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin>>n>>m;
    vector<pair<long long,long long>> graph[n];
    while(m--){
        long long a,b,w;
        cin>>a>>b>>w;
        graph[--a].push_back({w,--b});
    }
    priority_queue<pair<long long,long long>> mq;
    mq.push({0,0});
    vector<long long> dist(n,1e18);
    vector<bool> check(n,false);
    dist[0] = 0;
    while(!mq.empty()){
        pair<long long,long long> cur = mq.top();
        mq.pop();
        if(!check[cur.second]){
            check[cur.second] = true;
            for(pair<long long,long long> x : graph[cur.second]){
                if(dist[x.second] > dist[cur.second] + x.first){
                dist[x.second] = dist[cur.second]+x.first;
                mq.push({-dist[x.second],x.second});
                }
            }
        }
    }
    for(long long x : dist){
        cout<<x<<" ";
    }
    return 0;
}
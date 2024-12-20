#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> graph[n];
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        graph[--a].push_back({--b,w});
        graph[b].push_back({a,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mq;
    vector<bool> vis(n,false);
    long long ans = 0;
    mq.push({0,0});
    while(!mq.empty()){
        auto cur = mq.top();
        mq.pop();
        if(vis[cur.second]) continue;
        ans+=cur.first;
        vis[cur.second] = true;
        for(auto x : graph[cur.second]){
            mq.push({x.second,x.first});
        }
    }
    for(int i=0; i<n; i++){
        if(!vis[i]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
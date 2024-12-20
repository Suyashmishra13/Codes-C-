#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
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
    vector<int> minc(n,0);
    vector<int> maxc(n,0);
    vector<int> unique(n,0);
    // minc[0] = 1;
    // maxc[0] = 1;
    unique[0] = 1;
    while(!mq.empty()){
        pair<long long,long long> cur = mq.top();
        mq.pop();
        if(!check[cur.second]){
            check[cur.second] = true;
            for(pair<long long,long long> x : graph[cur.second]){
                if(dist[x.second] == dist[cur.second] + x.first){
                    minc[x.second] = min(minc[x.second],minc[cur.second]+1);
                    maxc[x.second] = max(maxc[x.second],maxc[cur.second]+1);
                    unique[x.second] += unique[cur.second];
                    unique[x.second]%=mod;
                }
                if(dist[x.second] > dist[cur.second] + x.first){
                    unique[x.second] = unique[cur.second];
                    minc[x.second] = minc[cur.second]+1;
                    maxc[x.second] = maxc[cur.second]+1;
                    dist[x.second] = dist[cur.second]+x.first;
                    mq.push({-dist[x.second],x.second});
                }
            }
        }
    }
    cout<<dist[n-1]<<" "<<unique[n-1]<<" "<<minc[n-1]<<" "<<maxc[n-1];
    return 0;
}
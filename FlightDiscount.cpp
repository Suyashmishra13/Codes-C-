#include <bits/stdc++.h>
using namespace std;
struct tuples{
    long long distfroms;
    long long nodeval;
    bool discount;
    tuples(long long a,long long b,bool x) : distfroms(a),nodeval(b),discount(x){};
};
struct cmp{
    bool operator()(const tuples &a,const tuples &b){
    return a.distfroms<b.distfroms;
};
};
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
    priority_queue<tuples,vector<tuples>,cmp> mq;
    mq.push(tuples{0,0,false});
    vector<vector<long long>> dist(n,vector<long long>(2,1e18));
    vector<bool> check(n,false);
    vector<pair<int,int>> p(n,{-1,0});
    dist[0][0] = 0;
    // dist[0][1] = 0;
    while(!mq.empty()){
        tuples now = mq.top();
        pair<long long,long long> cur = {now.distfroms,now.nodeval};
        mq.pop();
        // if(!check[cur.second]){
            // check[cur.second] = true;
        if(-now.distfroms != dist[cur.second][now.discount]) continue;
        if(cur.second == n-1) break;
            for(pair<long long,long long> x : graph[cur.second]){
                // if(dist[x.second][now.discount] > dist[cur.second][now.discount] + x.first){
                    if(!now.discount){
                        if(dist[x.second][!now.discount] > dist[cur.second][now.discount] + (x.first)/2 ){
                            dist[x.second][1] = dist[cur.second][0]+(x.first/2);
                            mq.push(tuples{-(dist[x.second][1]),x.second,1});
                        }
                    }
                    if(dist[x.second][now.discount] > dist[cur.second][now.discount] + (x.first)){
                        dist[x.second][now.discount] = dist[cur.second][now.discount]+x.first;
                        mq.push(tuples{-(dist[x.second][now.discount]),x.second,now.discount});
                    }
                // }
            }
        // }
    }
    cout<<dist[n-1][1];
    return 0;
}
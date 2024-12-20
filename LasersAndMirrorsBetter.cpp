#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    long long n,sx,sy,ex,ey;
    cin>>n>>sx>>sy>>ex>>ey;
    vector<long long> graph[n+2];
    vector<pair<long long,long long>> pts;
    pts.push_back({sx,sy});
    for(long long i=0; i<n; i++){
        long long a,b;
        cin>>a>>b;
        pts.push_back({a,b});
    }
    pts.push_back({ex,ey});
    for(long long i=0; i<pts.size(); i++){
        for(long long j=i+1; j<pts.size(); j++){
            if(pts[i].first == pts[j].first || pts[i].second == pts[j].second){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    vector<pair<long long,bool>> pred(n+2,{-1,false});
    pred[0] = {0,true};
    queue<pair<long long,bool>> q;
    q.push(pred[0]);
    while(!q.empty()){
        pair<long long,bool> curp = q.front();
        long long cur = curp.first;
        if(pts[cur].first == pts[n+1].first && pts[cur].second == pts[n+1].second){
            break;
        }
        bool curdir = curp.second;
        q.pop();
        for(long long x : graph[cur]){
            if(pred[x].first == -1){
                int ne = x;
                if(pts[ne].first != pts[cur].first && pts[ne].second == pts[cur].second && curdir){
                    q.push({x,curdir});
                    pred[x].first = pred[cur].first;
                }
                else if(pts[ne].first != pts[cur].first && pts[ne].second == pts[cur].second && !curdir){
                    q.push({x,!curdir});
                    pred[x].first = pred[cur].first + 1;
                }
                else if(pts[ne].first == pts[cur].first && pts[ne].second != pts[cur].second && curdir){
                    q.push({x,curdir});
                    pred[x].first = pred[cur].first + 1;
                }
                else if(pts[ne].first == pts[cur].first && pts[ne].second != pts[cur].second && !curdir){
                    q.push({x,!curdir});
                    pred[x].first = pred[cur].first;
                }
            }
        }
    }
    cout<<pred[n+1].first;
    return 0;
}
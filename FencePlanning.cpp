#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int cur,vector<bool> &vis,int &mxx,int &mnx,int &mxy,int &mny,vector<pair<int,int>> &xy){
    vis[cur] = true;
    mxx = max(mxx,xy[cur].first);
    mnx = min(mnx,xy[cur].first);
    mxy = max(mxy,xy[cur].second);
    mny = min(mny,xy[cur].second);
    for(int x : adj[cur]){
        if(!vis[x])
            dfs(adj,x,vis,mxx,mnx,mxy,mny,xy);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> xy(n);
    vector<int> adj[n];
    for(int i=0; i<n; i++){
        cin>>xy[i].first;
        cin>>xy[i].second;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int ans = INT_MAX;
    vector<bool> vis(n,false);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            int maxx = 0;
            int minx = INT_MAX;
            int miny = INT_MAX;
            int maxy = 0;
            dfs(adj,i,vis,maxx,minx,maxy,miny,xy);
            ans = min(ans,2*(maxx-minx + maxy-miny));
        }
    }
    cout<<ans<<endl;
    return 0;
}
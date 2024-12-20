#include <bits/stdc++.h>
using namespace std;
void dfs(int start,int &atleast,vector<pair<int,int>> adj[],int &ans,int &compare,vector<bool> &vis){
    vis[start] = true;
    for(auto x:adj[start]){
        if(!vis[x.first]){
            int n_compare = min(compare,x.second);
            if(n_compare >= atleast) {
                ans++;
                dfs(x.first,atleast,adj,ans,n_compare,vis);
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<n-1; i++){
        int start,end,relevance;
        cin>>start>>end>>relevance;
        adj[start].push_back({end,relevance});
        adj[end].push_back({start,relevance});
    }
    for(int i=0; i<q; i++){
        int k,video;
        cin>>k>>video;
        int ans = 0;
        int compare = INT_MAX;
        vector<bool> vis(n+1,false);
        dfs(video,k,adj,ans,compare,vis);
        cout<<ans<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>adj[],int cur,vector<bool> &vis){
    vis[cur] = true;
    for(int x : adj[cur]){
        if(!vis[x])
            dfs(adj,x,vis);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int k = 0;
    vector<bool> vis(n+1,false);
    vector<int> tobuildr;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(tobuildr.size() >= 1) tobuildr.push_back(i);
            tobuildr.push_back(i);
            k++;
            dfs(adj,i,vis);
        }
    }
    cout<<k-1<<endl;
    tobuildr.pop_back();
    if(k) for(int x:tobuildr) cout<<x<<" ";
    return 0;
}
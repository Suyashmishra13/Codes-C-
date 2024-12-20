#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[][2],int cur,int state,vector<bool> &vis){
    vis[cur] = true;
    for(int x:adj[cur][state]){
        if(!vis[x]){
            dfs(adj,x,state,vis);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1][2];
    for(int i=0; i<m; i++){
        int x , y;
        cin>>x>>y;
        adj[x][0].push_back(y);
        adj[y][1].push_back(x);
    }
    vector<bool> vis(n+1,false);
    dfs(adj,1,0,vis);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            cout<<1<<" "<<i;
            return 0;
        }
    }
    vis.resize(n+1);
    vector<bool> newvis(n+1,false);
    dfs(adj,1,1,newvis);
    for(int i=1; i<=n; i++){
        if(!newvis[i]){
            cout<<"NO"<<endl;
            cout<<i<<" "<<1;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
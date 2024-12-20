#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int cur,vector<int> &val,int change){
    val[cur] = change%2;
    change++;
    for(int x:adj[cur]){
        if(val[x] == -1){
            dfs(adj,x,val,change);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vals(n+1,-1);
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(vals[i] == -1){
            dfs(adj,i,vals,0);
        }
    }
    bool imp = false;
    for(int i=1; i<=n; i++){
        int o = vals[i];
        for(int x : adj[i]){
            if(vals[x] == o){
                imp = true;
                break;
            }
        }
    }
    if(!imp) {for(int x:vals) if(x!=-1) cout<<x+1<<" ";}
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
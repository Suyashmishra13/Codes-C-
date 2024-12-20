#include <bits/stdc++.h>
using namespace std;
bool isCyclic(int cur,int p,int start,vector<int> adj[],vector<bool> &vis){
    bool fans = false;
    vis[cur] = true;
    for(int x:adj[cur]){
        if(x == start && p != start) return true;
        if(x != p){
            fans = fans || isCyclic(x,cur,start,adj,vis);
            if(fans) break;
        }
    }
    if(fans) return true;
    vis[cur] = false;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int noe,edges;
    cin>>noe>>edges;
    vector<int> adj[noe+1];
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(noe+1,false);
    vector<vector<int>> ans;
    for(int i=1; i<= noe; i++){
        if(adj[i].empty() && !vis[i]){
            vis[i] = true; 
            ans.push_back({i});
        }
        else if(!vis[i]){
            vector<bool> nv(noe+1,false);
            vector<int> curans;
            bool cf = isCyclic(i,i,i,adj,nv);
            if(cf){
                for(int i=1; i<=noe; i++){
                    if(nv[i]) {
                        vis[i] = true;
                        curans.push_back(i);
                    }
                }
                ans.push_back(curans);
            }
        }
    }
    for(int i=1; i<=noe; i++) if(!vis[i]){cout<<"IMPOSSIBLE"; return 0;}
    for(vector<int> x:ans){
        if(x.size() == 1) {cout<<x[0]<<endl; continue;}
        else{
            for(int i=0; i<x.size()-1; i++){
                cout<<x[i]<<" "<<x[i+1]<<endl;
            }
            cout<<x[0]<<" "<<x[x.size()-1];
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void farthest(int cur,int p,vector<int> adj[],pair<int,int> &node,int curdist){
    if(node.second <= curdist){
        node.second = curdist;
        node.first = cur;
    }
    for(int x:adj[cur]){
        if(x != p){
            farthest(x,cur,adj,node,curdist+1);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pair<int,int> furthest = {-1,-1};
    farthest(1,0,adj,furthest,0);
    int ans = 0;
    pair<int,int> dia = {-1,-1};
    farthest(furthest.first,0,adj,dia,0);
    cout<<dia.second<<endl;
    return 0;
}
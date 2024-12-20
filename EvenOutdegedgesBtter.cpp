#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> ans;
bool vis[100001];
int reach[100001];
int odd[100001];
int timer = 1;
// Basically the give condition is that of a tree but with cycles/back edges present in it
// Hence we perform dfs but keep track of time while visiting each node
// After dfs has been performed and we are at node which has Odd outdegree then we join it
// with its parent node to make its outdegree even
// And if a node already has even outdegree then we let the edge get directed from parent to node
// So that nodes outdegree remains same but the parents outdeg increases
// Also if we encounter a node which can be reached after its neighbr has already been reached 
// That represents a cycle and we may direct that edge towards anyside toggling the corresponding outdeg values
void dfs(int cur,vector<int> graph[],int parent = 0){
    vis[cur] = true;
    reach[cur] = timer++;
    for(int neighbr : graph[cur]){
        if(neighbr != parent){
        if(!vis[neighbr]){
            dfs(neighbr,graph,cur);
            if(odd[neighbr]){
                ans.push_back({neighbr,cur});
                odd[neighbr] = 0;
            }
            else{
                ans.push_back({cur,neighbr}); 
                odd[cur]^=1;
            }
        }
        else if(reach[cur] > reach[neighbr]){
            ans.push_back({neighbr,cur});
            odd[neighbr]^=1;
        }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i])
            dfs(i,adj);
    }
    if(accumulate(odd+1,odd+n+1,0)) cout<<"IMPOSSIBLE"<<endl;
    else 
        for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
    return 0;
}
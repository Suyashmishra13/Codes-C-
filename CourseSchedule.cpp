#include <bits/stdc++.h>
using namespace std;
bool nf = false;
stack<int> ans;
void dfs(int cur,vector<int> graph[],vector<bool> &vis,vector<bool> &nc,int p = -1){
    vis[cur] = true;
    nc[cur] = true;
    for(int x:graph[cur]){
        if(!vis[x]){
            dfs(x,graph,vis,nc,cur);
        }
        else if(nc[x] && x != p){
            nf = true;
            return;
        }
    }
    nc[cur] = false;
    ans.push(cur);
    return;
}
struct cmp{
    bool operator()(const pair<pair<int,int>,int> &a ,const pair<pair<int,int>,int> &b){
        if(a.first.first == b.first.first) return a.first.second>b.first.second;
        return a.first.first<b.first.first;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    vector<int> indeg(n+1,0);
    vector<int> outdeg(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        indeg[b]++;
        outdeg[a]++;
    }
    vector<pair<pair<int,int>,int>> in;
    for(int i=0; i<=n; i++){
        if(i != 0) in.push_back({{indeg[i],outdeg[i]},i});
    }
    sort(in.begin(),in.end(), cmp());
    vector<int> sol;
    vector<bool> vis(n+1,false);
    for(auto x : in){
        int i = x.second;
        if(!vis[i]){
            vector<bool> fc(n+1,false);
            dfs(i,graph,vis,fc);
        }
    }
    if(nf) cout<<"IMPOSSIBLE"<<endl;
    else{
        while(!ans.empty()){
            sol.push_back(ans.top());
            ans.pop();
        }
        vector<int> check(n+1,-1);
        for(int i=0; i<sol.size(); i++){
            check[sol[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            int cur = check[i];
            for(int x: graph[i]){
                if(check[x] < check[i]){
                    cout<<"IMPOSSIBLE";
                    return 0;
                }
            }
        }
        
        for(int x: sol) cout<<x<<" ";
        
    }
    return 0;
}
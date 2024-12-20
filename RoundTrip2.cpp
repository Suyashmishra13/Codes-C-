#include <bits/stdc++.h>
using namespace std;
// bool cycle = false;
const int s = 1e5+1;
bool check[s];
vector<int> sol;
vector<int> cycles;
void dfs(int cur,vector<int> graph[],vector<bool> &vis,vector<int> ans={}){
    vis[cur] = true;
    check[cur] = true;
    ans.push_back(cur);
    for(int x : graph[cur]){
        if(!check[x]){
            dfs(x,graph,vis,ans);
        }
        else if(vis[x]){
            sol.push_back(cur);
        }
    }
    // if(cycle){
    //     sol.push_back(ans);
    // }
    vis[cur] = false;
    return;
}
void cycle(int cur,vector<int> graph[],vector<bool> &v,int &start,vector<int> ans = {}){
    v[cur] = true;
    ans.push_back(cur);
    for(int x:graph[cur]){
        if(!v[x]){
            cycle(x,graph,v,start,ans);
        }
        else{
            if(x == start){
                cycles = ans;
                return;
            }
        }
    }
    if(!cycles.empty()) return;
    ans.pop_back();
    v[cur] = false;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[--a].push_back(--b);
    }
    for(int i=0; i<n; i++){
        if(!check[i]){
        vector<bool> vis(n,false);
        dfs(i,graph,vis);}
    }
    if(sol.empty()){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int x:sol){
        vector<bool> vis(n,false);
        cycle(x,graph,vis,x);
        if(!cycles.empty()) break;
    }
    cout<<cycles.size()+1<<endl;
    for(int x : cycles){
        cout<<x+1<<" ";
    }
    cout<<cycles[0]+1<<endl;
    return 0;
}
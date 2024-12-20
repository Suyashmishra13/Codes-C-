#include <bits/stdc++.h>
using namespace std;
void dfs(int cur,vector<int> adj[],vector<bool> &vis,vector<int> &assigned,vector<char> &type,int &valtba){
    vis[cur] = true;
    assigned[cur] = valtba;
    for(auto x:adj[cur]){
        if(!vis[x] && type[x] == type[cur]){
            dfs(x,adj,vis,assigned,type,valtba);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    int num,friends;
    cin>>num>>friends;
    vector<int> adj[num+1];
    vector<char> typeofm(num+1);
    string type;
    cin>>type;
    for(int i=0;i<num-1; i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0; i<num; i++){
        typeofm[i+1] = type[i];
    }
    vector<int> assigned(num+1,0);
    vector<bool> vis(num+1,false);
    int component = 0;
    for(int i=1; i<=num; i++){
        if(!vis[i] && typeofm[i] == 'H')
            dfs(i,adj,vis,assigned,typeofm,component);
        else if(!vis[i] && typeofm[i] == 'G')
            dfs(i,adj,vis,assigned,typeofm,component);
        component++;
    }
    while(friends--){
        int start,end;
        char typereq;
        cin>>start>>end;
        cin>>typereq;
        if(assigned[start] != assigned[end]){
            cout<<1;
        }
        else if(assigned[start] == assigned[end] && typereq == typeofm[start]){
            cout<<1;
        }
        else cout<<0;
        
    }
    return 0;
}
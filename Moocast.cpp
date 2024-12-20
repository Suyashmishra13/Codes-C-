#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int cur,vector<bool> &vis,int &k){
    vis[cur] = true;
    k++;
    for(int x:adj[cur]){
        if(!vis[x])
            dfs(adj,x,vis,k);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n;
    cin>>n;
    vector<pair<int,int>> coor(n);
    vector<int> power(n);
    //reading input
    for(int i=0; i<n; i++){
        cin>>coor[i].first;
        cin>>coor[i].second;
        cin>>power[i];
    }
    vector<int> adj[n];
    auto connected = [&](int first,int second){
        int distbtw = ((abs(coor[first].first - coor[second].first) * abs(coor[first].first - coor[second].first)) + (abs(coor[first].second - coor[second].second) * abs(coor[first].second - coor[second].second)));
        int effectpower = power[first];
        effectpower *= effectpower;
        return effectpower >= distbtw;
    };  
    // Following the one way approach because transmission is one way :
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(connected(i,j) && i != j){
                adj[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        vector<bool> vis(n,false);
            int k = 0;
            dfs(adj,i,vis,k);
            ans = max(ans,k);
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<pair<int,bool>> adj[],int cur,vector<bool> &vis,int curval,vector<int> &assigned,int &ans,bool &nf){
    vis[cur] = true;
    assigned[cur] = curval%2;
    for(pair<int,bool> x: adj[cur]){
        if(assigned[x.first] == -1){
            if(x.second){
                dfs(adj,x.first,vis,curval,assigned,ans,nf);
            }
            else{
                dfs(adj,x.first,vis,curval+1,assigned,ans,nf);
            }
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<pair<int,bool>> adj[n+1];
    for(int i=0; i<m; i++){
        char x;
        int a,b;
        cin>>x;
        cin>>a>>b;
        adj[a].push_back({b,x == 'S'});
        adj[b].push_back({a,x == 'S'});
    }
    int ans = 0;
    int curval = 1;
    bool notfound = false;
    bool nf = false;
    vector<bool> vis(n+1,false);
    vector<int> assigned(n+1,-1);
    for(int i=1; i<=n ; i++){
        if(assigned[i] == -1){
            ans++;
            dfs(adj,i,vis,curval,assigned,ans,notfound);
        }
    }
    for(int i=1; i<=n ;i++){
        int cura = assigned[i];
        for(auto x : adj[i]){
            if(x.second){
                if(assigned[x.first] != cura){
                    nf = true; break;
                }
            }
            else{
                if((assigned[x.first] + 1)%2 != cura){
                nf = true; break;
                }
            }
        }
    }
    if(!nf){
        cout<<1;
        while(ans--){
            cout<<0;
        }
    }
    else cout<<0<<endl;
    return 0;
}
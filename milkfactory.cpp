#include <iostream>
#include <vector>
using namespace std;
void dfs(int cur,vector<int> &count,vector<int> adj[]){
    count[cur]++;
    for(int x : adj[cur]){
        dfs(x,count,adj);
    }
    return;
}

int main(){
    freopen("factory.in","r",stdin);
    freopen("factory.out","w",stdout);
    int n;
    cin>>n;
    vector<int> adj[n];
    for(int i=0; i<n-1 ;i++){
        int a,b;
        cin>>a>>b;
        adj[--a].push_back(--b);
    }
    int ans = -1;
    vector<int> count(n,0);
    for(int i=0; i<n; i++){
        dfs(i,count,adj);
    }
    for(int i=0; i<n; i++){
        if(count[i] == n){
            ans = i+1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
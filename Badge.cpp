#include <bits/stdc++.h>
using namespace std;
int p[1001];
bool cycle = false;
vector<int> ans(1001,-1);
void dfs(int cur){
    if(ans[cur] != -1){
        if(ans[cur] == 0){
            ans[cur] = cur;
            cycle = true;
        }
        return;
    }
    ans[cur] = 0;
    dfs(p[cur]);
    if(ans[cur] != 0){
        cycle = false;
    }
    else{
        ans[cur] = cycle ? cur : ans[p[cur]];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>p[i];
    }
    for(int i=1; i<=n; i++){
        dfs(i);
    }
    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
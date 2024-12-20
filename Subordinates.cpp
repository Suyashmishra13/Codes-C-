#include <bits/stdc++.h>
using namespace std;
const int sze = 2e5+1;
int sub_size[sze];
void dfs(vector<int> p[],int cur){
    sub_size[cur] = 1;
    for(int x : p[cur]){
        dfs(p,x);
        sub_size[cur] += sub_size[x];
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> parents[n+1];
    for(int i=2; i<n+1; i++){
        int x;
        cin>>x;
        parents[x].push_back(i);
    }
    dfs(parents,1);
    for(int i=1; i<=n; i++){
        cout<<sub_size[i]-1<<" "<<endl;
    }
    return 0;
}
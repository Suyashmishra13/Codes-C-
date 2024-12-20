#include <bits/stdc++.h>
using namespace std;
int ans = INT_MIN;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    int n,m,c;
    cin>>n>>m>>c;
    vector<int> money(n);
    for(int i=0; i<n; i++) cin>>money[i];
    vector<int> graph[n];
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[--a].push_back(--b);
    }
    vector<vector<int>> dp(2001,vector<int>(n,-1));
    dp[0][0] = 0;
    for(int i=0; i<=1000; i++){
        for(int j=0; j<n; j++){
            if(dp[i][j] != -1){
                for(int son : graph[j])
                    dp[i+1][son] = max(dp[i][j]+money[son],dp[i+1][son]);
            }
        }
        ans = max(ans,dp[i][0] - c*i*i);
    }
    cout<<ans<<endl;
    return 0;
}
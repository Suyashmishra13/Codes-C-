#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+2,vector<int>(m+2,INT_MAX));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) dp[i][0] = min(dp[i][0],dp[i-1][0] + 1);
    for(int i=1; i<=m; i++) dp[0][i] = min(dp[0][i],dp[0][i-1] + 1);
    // dp[0][1] = a[0] != b[0];
    // dp[1][0] = a[0] != b[0];
    // dp[1][1] = (a[0] != b[0]);
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            dp[i][j] = min(dp[i][j],min((dp[i-1][j]+1),(dp[i][j-1]+1)));
            if(i-1 < n && j-1 < m) {int cost = (a[i-1] != b[j-1]); dp[i][j] = min(dp[i][j],dp[i-1][j-1] + cost);}
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
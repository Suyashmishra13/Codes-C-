#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        if(grid[i][0] != '*') {dp[i][0] = 1;}
        else break;
    }
    for(int i=0; i<n; i++){
        if(grid[0][i] != '*') {dp[0][i] = 1;}
        else break;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(grid[i][j] != '*'){
                dp[i][j] += (dp[i-1][j] + dp[i][j-1]);
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}
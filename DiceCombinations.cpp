#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int solve(int cur){
    if(cur < 0) return 0;
    if(cur == 0) return 1;
    if(cur == 1) return 1;
    return solve(cur-1) + solve(cur-2) + solve(cur-3) + solve(cur-4) + solve(cur-5) + solve(cur-6);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long long dp[n+7];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    // cout<<solve(n)%mod<<endl;
    for(int i=6; i<=n; i++){
        dp[i] = (dp[i-1]%mod) + (dp[i-2]%mod) + (dp[i-3]%mod) + (dp[i-4]%mod) + (dp[i-5]%mod) + (dp[i-6]%mod);
        dp[i]%=mod;
    }
    cout<<dp[n];
    return 0;
}
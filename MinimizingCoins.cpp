#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,target;
    cin>>n>>target;
    vector<long long> denom(n);
    for(long long i=0; i<n; i++) cin>>denom[i];
    vector<long long> dp(target+1,INT_MAX);
    dp[0] = 0;
    for(long long i=0;i<=target;i++){
        for(long long j=0; j<n; j++){
            if(i-denom[j] >= 0){
                dp[i] = min(dp[i],dp[i-denom[j]]+1);
            }
        }
    }
    dp[target] == INT_MAX ? cout<< -1 : cout<<dp[target];
    return 0;
}
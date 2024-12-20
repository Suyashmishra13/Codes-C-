#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,target;
    cin>>n>>target;
    vector<long long> denom(n);
    for(long long i=0; i<n; i++) cin>>denom[i];
    vector<long long> dp(target+1,0);
    dp[0] = 0;
    for(int i=0; i<n; i++){
        if(denom[i] < target+1)dp[denom[i]] = 1;
    }
    for(long long i=0;i<=target;i++){
        for(long long j=0; j<n; j++){
            if(i-denom[j] >= 0){
                dp[i]+= (dp[i-denom[j]]);
                dp[i]%=mod;
            }
        }
    }
    cout<<dp[target];
    return 0;
}
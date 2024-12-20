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
    dp[0] = 1;
    for(long long i=0;i<n;i++){
        for(long long j=0; j<=target; j++){
            if(j-denom[i] >= 0){
                dp[j]+= (dp[j-denom[i]]);
                dp[j]%=mod;
            }
        }
    }
    cout<<dp[target];
    return 0;
}
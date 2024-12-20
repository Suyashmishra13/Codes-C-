#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> coins(n);
    for(int &x : coins) cin>>x;
    int ans = coins[0];
    int range = accumulate(coins.begin(),coins.end(),0);
    int dp[range+1] = {0};
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=range; j>=0; j--){
            if(j - coins[i] >= 0) dp[j] += dp[j-coins[i]];
        }
    }
    int count = 0;
    for(int j=1; j<=range; j++){
            if(dp[j]) count++;
        }
    cout<<count<<endl;
    for(int j=1; j<=range; j++){
        if(dp[j]) cout<<j<<" ";
    }
    return 0;
}
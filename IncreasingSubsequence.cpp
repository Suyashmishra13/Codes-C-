#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    vector<long long> a(n);
    vector<long long> fans;
    for(long long &x:a) cin>>x;
    vector<long long> dp(n+1,0); // check the size with which u need to initialize this again
    long long ans = -1;
    long long end = -1;
    for(long long i=0; i<n; i++){
        dp[a[i]] = dp[a[i]-1] + 1;
        if(dp[a[i]] > ans){
            end = a[i];
            ans = dp[a[i]];
        }
    }
    cout<<ans;
    for(long long i=n-1; i>=0; i--){
        if(a[i] == end){
            fans.push_back(i+1);
            end--;
        }
    }
    for(long long i=(fans.size()-1); i>=0; i--){
        cout<<fans[i]<<" ";
    }
    return 0;
}
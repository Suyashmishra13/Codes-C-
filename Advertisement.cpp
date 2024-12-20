#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(long long &x : nums) cin>>x;
    stack<pair<long long,long long>> c;
    long long ans = INT_MIN;
    for(long long i=0; i<n; i++){
        long long cur = i;
        while(!c.empty() && nums[i] < c.top().first){
            auto now = c.top();
            c.pop();
            cur = now.second;
            ans = max(ans,((i - now.second) * now.first));
        }
        c.push({nums[i],cur});
    }
    while(!c.empty()){
        auto now = c.top();
        c.pop();
        ans = max(ans,((n - now.second) * now.first));
    }
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N], c[N], pos[N];
vector<int> lis;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        pos[a] = i;
    }
    for(int i=1; i<=n; i++){
        int b;
        cin>>b;
        c[i] = pos[b];
    }
    vector<int> dp(n+1,INT_MAX);
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++){
        int j = upper_bound(dp.begin(),dp.end(),c[i]) - dp.begin();
        if(dp[j-1] < c[i] && dp[j] > c[i]){
            dp[j] = c[i];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(dp[i] < INT_MAX) ans = i;
    }
    cout<<ans;
    return 0;
}
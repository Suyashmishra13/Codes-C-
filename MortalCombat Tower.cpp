#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int> &type, int &ans, int val = 0, bool toggle = true) {
    if (index >= type.size()) {
        ans = min(ans, val);
        return;
    }
    if (toggle) {
        if (index + 1 <= type.size()) solve(index + 1, type, ans, val + type[index], false);
        if (index + 2 <= type.size()) solve(index + 2, type, ans, val + type[index] + (index + 1 < type.size() ? type[index + 1] : 0), false);
    } else {
        if (index + 1 <= type.size()) solve(index + 1, type, ans, val, true);
        if (index + 2 <= type.size()) solve(index + 2, type, ans, val, true);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int l = 0; l < test; l++) {
        int n;
        cin >> n;
        vector<int> type(n);
        for (int i = 0; i < n; i++) {cin >> type[i];}
        int ans = INT_MAX;

        // Uncomment to use the recursive solution
        // solve(0, type, ans);
        // cout << ans << endl;

        // Using dynamic programming approach
        vector<vector<int>> dp(n + 1, vector<int>(2,1e9));
        dp[0][1] = 0;
        for (int i = 0; i < n; i++) {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + type[i]);
            if (i + 2 <= n) {
                dp[i + 2][1] = min(dp[i + 2][1], dp[i][0]);
                dp[i + 2][0] = min(dp[i + 2][0], dp[i][1] + type[i+1] + type[i]);
            }
        }
        cout << min(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}

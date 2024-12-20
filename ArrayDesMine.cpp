#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
    if (a[0] == 0)
    {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }
    else
        dp[0][a[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j - 1 >= 0)
                    (dp[i][j] += dp[i - 1][j - 1]) %= mod;
                if (j + 1 <= m)
                    (dp[i][j] += dp[i - 1][j + 1]) %= mod;
                (dp[i][j] += dp[i - 1][j]) %= mod;
            }
        }
        else
        {
            if (a[i] - 1 >= 0)
                (dp[i][a[i]] += dp[i - 1][a[i] - 1]) %= mod;
            if (a[i] + 1 <= m)
                (dp[i][a[i]] += dp[i - 1][a[i] + 1]) %= mod;
            (dp[i][a[i]] += dp[i - 1][a[i]]) %= mod;
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; j++)
        (ans += dp[n - 1][j]) %= mod;
    cout << (ans + mod) % mod;
    return 0;
}
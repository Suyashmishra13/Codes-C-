#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(1 + dp[i - 1][j], 1 + dp[i][j - 1]);
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }
    cout << dp[n][m];
    return 0;
}
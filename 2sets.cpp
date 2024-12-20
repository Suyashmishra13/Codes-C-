#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int sze = 2e6 + 1;
long long dp[sze];
long long mod_exp(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1) // If exp is odd, multiply base with result
            result = (result * base) % mod;
        base = (base * base) % mod; // Square the base
        exp /= 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long ts = (n * (n + 1) / 2);
    fill(dp, dp + sze, 0);
    dp[0] = 1;
    if ((ts & 1) == 1)
        cout << 0 << endl;
    else
    {
        // ts = (ts >> 1);
        ts = (ts / 2);
        for (long long i = 1; i <= n; i++)
        {
            for (long long j = ts; j >= i; j--)
            {
                if (j - i >= 0)
                    dp[j] += dp[j - i];
                dp[j] %= mod;
            }
        }
        cout << (dp[ts] * 500000004) % mod << endl;
    }
    return 0;
}
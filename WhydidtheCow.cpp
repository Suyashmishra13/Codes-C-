#include <bits/stdc++.h>
using namespace std;

void setIO(string prob)
{
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}

const int MAX_N = 1e5;

int sigs[MAX_N];
int presum[MAX_N];

int main()
{
    setIO("maxcross");
    int n, k, b;
    cin >> n >> k >> b;
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        sigs[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        presum[i + 1] = sigs[i + 1] + presum[i];
    }

    int ret = INT_MAX;
    for (int i = 0; i <= n - k; i++)
    {
        ret = min(ret, presum[i + k] - presum[i]);
    }
    cout << ret << '\n';
}
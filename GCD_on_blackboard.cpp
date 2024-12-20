#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    ll ans = INT_MIN;
    vector<bool> t(n, true);
    vector<int> left(n + 1, 0);
    left[0] = a[0];
    vector<int> right(n + 1, 0);
    right[n] = a[n - 1];
    for (int i = 0; i < n; i++)
    {
        left[i + 1] = gcd(left[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = gcd(right[i + 1], a[i]);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        ll cg = gcd(left[i], right[i + 1]);
        ans = max(ans, cg);
    }
    ll fc = max(left[n - 1], right[1]);
    ans = max(ans, fc);
    cout << ans << endl;
}

int main()
{
    int t;
    t = 1;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
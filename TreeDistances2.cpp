#include <bits/stdc++.h>
using namespace std;
#define ll long long
void dfs(vector<ll> tree[], vector<ll> &ans, vector<ll> &dp, ll cur, ll parent, ll curd = 0)
{
    ans[0] += curd;
    dp[cur] = 1;
    for (ll x : tree[cur])
    {
        if (x != parent)
        {
            dfs(tree, ans, dp, x, cur, curd + 1);
            dp[cur] += dp[x];
        }
    }
    return;
}

void dfssec(vector<ll> tree[], vector<ll> &ans, vector<ll> &dp, ll cur, ll parent, ll curd = 0)
{
    for (ll x : tree[cur])
    {
        if (x != parent)
        {
            ans[x] = ans[cur] + ans.size() - 2 * dp[x];
            dfssec(tree, ans, dp, x, cur, curd + 1);
        }
    }
    return;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> graph[n];
    vector<bool> vis(n, false);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    vector<ll> ans(n, 0);
    vector<ll> dp(n, 0);
    dfs(graph, ans, dp, 0, -1);
    dfssec(graph, ans, dp, 0, -1);
    for (ll x : ans)
        cout << x << " ";
    return 0;
}

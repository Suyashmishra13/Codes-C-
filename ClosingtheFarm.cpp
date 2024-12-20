#include <bits/stdc++.h>
using namespace std;
vector<int> graph[3001];
vector<int> closing(3001);
vector<bool> vis(3001, false);
vector<bool> closed(3001, false);
void dfs(int &check, int cur)
{
    if (vis[cur] || closed[cur])
        return;
    vis[cur] = true;
    check++;
    for (int x : graph[cur])
    {
        if (!vis[x])
            dfs(check, x);
    }
    // vis[cur] = false;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> closing[i];
    }
    int check = 0;
    dfs(check, 1);
    // cout<<check<<endl;
    if (check == n)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    int rl = n - 1;
    int k = 0;
    fill(vis.begin(), vis.end(), false);
    while (rl)
    {
        closed[closing[k++]] = true;
        fill(vis.begin(), vis.end(), false);
        check = 0;
        dfs(check, closing[n - 1]);
        // cout<<check<<endl;
        if (check == rl)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        rl--;
    }
    return 0;
}
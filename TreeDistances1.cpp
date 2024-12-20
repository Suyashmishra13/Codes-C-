#include <bits/stdc++.h>
using namespace std;

void dfs(int cur, vector<int> graph[], pair<int, long long> &dap, long long curdis = 0, int parent = -1)
{
    if (dap.second < curdis)
    {
        dap.first = cur;
        dap.second = curdis;
    }
    for (int neighbr : graph[cur])
    {
        if (neighbr != parent)
            dfs(neighbr, graph, dap, curdis + 1, cur);
    }
    return;
}

bool upddist(int cur, int &dest, vector<int> tree[], vector<bool> &vis, vector<long long> &dist, int parent = -1, long long curdist = 0, long long maxdist = LLONG_MAX)
{
    if (cur == dest)
    {
        maxdist = curdist;
        dist[dest] = curdist;
        vis[dest] = true;
        return true;
    }
    for (int neighbr : tree[cur])
    {
        if (neighbr != parent)
        {
            if (upddist(neighbr, dest, tree, vis, dist, cur, curdist + 1, maxdist))
            {
                vis[cur] = true;
                dist[cur] = max(curdist, dist[dest] - curdist);
                return true;
            }
        }
    }
    return false;
}

int branchdfs(int cur, vector<int> graph[], vector<bool> &vis, vector<long long> &dist, long long curdist = 0, int parent = -1)
{
    if (vis[cur])
        return cur;
    for (int neighbr : graph[cur])
    {
        if (neighbr != parent)
        {
            int check = branchdfs(neighbr, graph, vis, dist, curdist + 1, cur);
            if (check != -1)
            {
                vis[cur] = true;
                dist[cur] = max(dist[cur], dist[check] + 1);
                return cur;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> graph[n];
    vector<bool> vis(n, false);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    pair<int, long long> dur = {-1, -1};
    dfs(0, graph, dur);
    pair<int, long long> sec = {-1, -1};
    dfs(dur.first, graph, sec);
    vector<long long> dist(n, 0);
    upddist(dur.first, sec.first, graph, vis, dist);
    dist[dur.first] = max(dist[dur.first], dist[sec.first]);
    dist[sec.first] = max(dist[dur.first], dist[sec.first]);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            branchdfs(i, graph, vis, dist);
        }
    }
    for (long long x : dist)
        cout << x << " ";
    return 0;
}

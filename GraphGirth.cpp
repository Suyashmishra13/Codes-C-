#include <bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> graph[n];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    vector<int> vis(n, false);
    queue<int> mq;
    for (int i = 0; i < n; i++)
    {
        int distance = 0;
        vis[i] = true;
        vector<int> dist(n, -1);
        dist[i] = 0;
        mq.push(i);
        while (!mq.empty())
        {
            int cur = mq.front();
            vis[cur] = true;
            mq.pop();
            for (int x : graph[cur])
            {
                if (dist[x] == -1)
                {
                    mq.push(x);
                    dist[x] = dist[cur] + 1;
                }
                else if (dist[x] >= dist[cur])
                {
                    ans = min(ans, dist[x] + dist[cur] + 1);
                }
            }
        }
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
    return 0;
}

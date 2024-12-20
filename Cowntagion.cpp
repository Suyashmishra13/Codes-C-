#include <bits/stdc++.h>

using namespace std;

#define maxn 100005

int n;
vector<int> adj[maxn];

int dfs(int start, int parent)
{
    int ans = 0;
    int cows = adj[start].size();
    if (parent == -1)
    {
        // parent node is currently root node
        cows++;
    }

    int currCows = 1;
    int days = 0;
    // count the number of superspreader events needed
    while (currCows < cows)
    {
        days++;
        currCows *= 2;
    }
    // send one cow to each adjacent farm without a sick cow
    ans += days;

    for (auto next : adj[start])
    {
        if (next != parent)
        {
            ans += dfs(next, start) + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(0, -1) << endl;
    return 0;
}
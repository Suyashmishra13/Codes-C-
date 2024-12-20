#include <bits/stdc++.h>
using namespace std;
struct triplet
{
    int a, b, c;
    triplet(int x, int y, int z) : a(x), b(y), c(z) {}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int a, b, k, m;
    cin >> a >> b >> k >> m;
    int x = max(a, b);
    int y = min(a, b);
    int ans = INT_MAX;
    bool vis[x + 1][y + 1] = {};
    triplet *start = new triplet(0, 0, k);
    queue<triplet *> minops;
    minops.push(start);
    while (!minops.empty())
    {
        triplet *cur = minops.front();
        minops.pop();
        ans = min(ans, abs(m - cur->a - cur->b));
        if (cur->a < x)
        {
            triplet *n = new triplet(x, cur->b, cur->c - 1);
            if (n->c >= 0 && !vis[n->a][n->b])
            {
                minops.push(n);
                vis[n->a][n->b] = true;
            }
        }
        if (cur->b < y)
        {
            triplet *n = new triplet(cur->a, y, cur->c - 1);
            if (n->c >= 0 && !vis[n->a][n->b])
            {
                minops.push(n);
                vis[n->a][n->b] = true;
            }
        }
        if (cur->a > 0)
        {
            triplet *n = new triplet(0, cur->b, cur->c - 1);
            if (n->c >= 0 && !vis[n->a][n->b])
            {
                minops.push(n);
                vis[n->a][n->b] = true;
            }
        }
        if (cur->b > 0)
        {
            triplet *n = new triplet(cur->a, 0, cur->c - 1);
            if (n->c >= 0 && !vis[n->a][n->b])
            {
                minops.push(n);
                vis[n->a][n->b] = true;
            }
        }
        if (cur->a < x)
        {
            int naval = cur->a + cur->b <= x ? cur->a + cur->b : x;
            int nbval = cur->a + cur->b <= x ? 0 : cur->b - (x - cur->a);
            // if (naval == -1 || nbval == -1)
            // {
            //     naval = x;
            //     nbval = cur->b - (x - cur->a);
            // }
            triplet *n = new triplet(naval, nbval, cur->c - 1);
            if (n->c >= 0 && !vis[n->a][n->b])
            {
                minops.push(n);
                vis[n->a][n->b] = true;
            }
        }
        if (cur->b < y)
        {
            int nbval = cur->a + cur->b <= y ? cur->a + cur->b : y;
            int naval = cur->a + cur->b <= y ? 0 : cur->a - (y - cur->b);
            // if (naval == -1 || nbval == -1)
            // {
            //     nbval = y;
            //     naval = cur->a - (y - cur->b);
            // }
            triplet *n = new triplet(naval, nbval, cur->c - 1);
            if (n->c >= 0 && !vis[n->a][n->b])
            {
                minops.push(n);
                vis[n->a][n->b] = true;
            }
        }
        if (cur->c < 0)
            break;
    }
    cout << ans << endl;
    return 0;
}

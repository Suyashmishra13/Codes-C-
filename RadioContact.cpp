#include <cstdio>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;

// using int = long long;

const int MAX_D = 1e18;
struct Coord
{
public:
    int x, y;
};

int dist(const pair<int, int> &a, const pair<int, int> &b)
{
    int x = (a.first - b.first);
    int y = (a.second - b.second);

    return (x * x) + (y * y);
}

int32_t main()
{
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int f, b;
    cin >> f >> b;

    pair<int, int> cf;
    pair<int, int> cb;
    cin >> cf.first >> cf.second;
    cin >> cb.first >> cb.second;
    pair<int, int> copyf = cf;
    pair<int, int> copyb = cb;
    string fp, bp;
    cin >> fp >> bp;
    vector<pair<int, int>> hs(f);
    vector<pair<int, int>> gs(b);
    for (int i = 0; i < f; i++)
    {
        if (fp[i] == 'N')
        {
            cf.second++;
        }
        if (fp[i] == 'S')
        {
            cf.second--;
        }
        if (fp[i] == 'E')
            cf.first++;
        if (fp[i] == 'W')
            cf.first--;
        hs[i].first = cf.first;
        hs[i].second = cf.second;
    }
    for (int i = 0; i < b; i++)
    {
        if (bp[i] == 'N')
        {
            cb.second++;
        }
        if (bp[i] == 'S')
        {
            cb.second--;
        }
        if (bp[i] == 'E')
            cb.first++;
        if (bp[i] == 'W')
            cb.first--;
        gs[i].first = cb.first;
        gs[i].second = cb.second;
    }
    vector<vector<int>> min_dist(
        f + 1, vector<int>(b + 1, INT_MAX));

    min_dist[0][0] = 0;
    min_dist[0][1] = dist(copyf, gs[0]);
    min_dist[1][0] = dist(copyb, hs[0]);
    for (int i = 0; i < fp.length(); i++)
    {
        for (int j = 0; j < bp.length(); j++)
        {
            if (i > 0)
            {
                min_dist[i][j] =
                    min(min_dist[i][j],
                        min_dist[i - 1][j] + dist(hs[i - 1], gs[j - 1]));
            }

            if (j > 0)
            {
                min_dist[i][j] =
                    min(min_dist[i][j],
                        min_dist[i][j - 1] + dist(hs[i - 1], gs[j - 1]));
            }

            if (i > 0 && j > 0)
            {
                min_dist[i][j] =
                    min(min_dist[i][j],
                        min_dist[i - 1][j - 1] + dist(hs[i - 1], gs[j - 1]));
            }
        }
    }

    cout << min_dist[f][b] << endl;
}
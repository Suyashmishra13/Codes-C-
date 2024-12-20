#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    int K, N;
    cin >> K >> N;
    for (int i = 0; i < N; i++)
    {
        int X; // max finish speed limit
        cin >> X;
        int ans = 0;
        int r = K; // remaining distance
        int s = 1; // speed
        // s increases up to X-1
        while (r > 0 && s < X)
        {
            ans++;
            r -= s;
            s++;
        }
        // now, X is achieved
        // the increasing speed and its corresponding
        // decreasing speed are managed at the same time
        // example with X=5, (n) marks the current speed
        // (5) : 1 move  for a total distance up to 5
        // 5 (5) : 2 moves for a total distande up to 10
        // 5 (6) 5 : 3 moves for a total distance up to 16
        // 5 6 (6) 5 : 4 moves for a total distance up to 22
        // 5 6 (7) 6 5 : 5 moves for a total distance up to 29
        // 5 6 7 (7) 6 5 : 6 moves for a total distance up to 36
        // and so on ...
        bool first = true;
        while (r > 0)
        {
            ans++;
            r -= s;
            if (first)
                first = false;
            else
            {
                s++;
                first = true;
            }
        }
        cout << ans << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    int c = n;
    // cout<<1<<endl;
    while (c--)
    {
        int t, v;
        cin >> t >> v;
        a.push_back({v, t});
    }
    // cout<<2<<endl;
    sort(a.begin(), a.end());
    int ans = INT_MIN;
    int left = 0;
    int right = n - 1;
    // cout<<3<<endl;
    while (left < right)
    {
        int chota = min(a[left].second, a[right].second);
        ans = max(ans, a[left].first + a[right].first);
        a[left].second = a[left].second - chota;
        a[right].second = a[right].second - chota;
        if (a[left].second == 0)
            left++;
        if (a[right].second == 0)
            right--;
        if (left > right)
            break;
        // cout<<chota<<" "<<left<<" "<<right<<endl;
    }
    cout << ans << endl;
    return 0;
}
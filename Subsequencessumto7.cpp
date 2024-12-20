#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
int main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int n;
    cin >> n;
    vector<ll> bids(n);
    map<ll, ll> prefix, first;
    ll sum = 0;
    ll ans = -1;
    for (ll i = 0; i < n; i++)
    {
        cin >> bids[i];
        sum += bids[i];
        bids[i] = ((sum) % 7);
        if (first.find((sum) % 7) == first.end())
            first[(sum) % 7] = i;
        else
        {
            ans = max(ans, i - first[(sum) % 7]);
        }
        if (sum % 7 == 0)
        {
            ans = max(i + 1, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    map<char, int> prefix, total;
    char opt[3] = {'P', 'H', 'S'};
    int ans = 0;
    vector<char> gesture(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gesture[i];
        total[gesture[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        prefix[gesture[i]]++;
        if (gesture[i] == 'P')
        {
            ans = max(max(ans, total['H'] - prefix['H'] + prefix[gesture[i]]), total['S'] - prefix['S'] + prefix[gesture[i]]);
        }
        else if (gesture[i] == 'H')
        {
            ans = max(max(ans, total['P'] - prefix['P'] + prefix[gesture[i]]), total['S'] - prefix['S'] + prefix[gesture[i]]);
        }
        else
        {
            ans = max(max(ans, total['H'] - prefix['H'] + prefix[gesture[i]]), total['P'] - prefix['P'] + prefix[gesture[i]]);
        }
    }
    cout << ans << endl;
    return 0;
}
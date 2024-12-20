#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> prefix(n + 1, 0);
    for (int i = 1, l; i <= n; i++)
    {
        cin >> l;
        prefix[i] = l + prefix[i - 1];
    }
    prefix[0] = 0;
    multiset<long long> ms;
    for (int i = 1; i <= n - b + a - 1; i++)
    {
        ms.insert(prefix[i]);
        if (ms.size() > b - a + 1)
        {
            ms.erase(ms.find(prefix[i - b - 1 + a]));
        }
        prefix[0] = (prefix[0] > prefix[i + b - a + 1] - *ms.begin() ? prefix[0] : prefix[i + b - a + 1] - *ms.begin());
    }
    cout << prefix[0] << endl;
    return 0;
}
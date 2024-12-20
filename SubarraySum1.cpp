#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long &x : a)
        cin >> x;
    map<long long, long long> cnt;
    cnt[0] = 1;
    long long cursum = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        cursum += a[i];
        ans += cnt[cursum - k];
        cnt[cursum]++;
    }
    cout << ans << endl;
    return 0;
}
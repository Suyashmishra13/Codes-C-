#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, k;
    cin>>n>>k;
    vector<long long> a(n);
    for (long long &x : a) cin>>x;
    long long l = 0, r = 0;
    map<long long,long long> f;
    long long ans = 0;
    while (l < n) {
        while(r < n && f.size() < k){
            f[a[r++]]++;
        }
        if(r < n && f.find(a[r]) != f.end()){
            while(r < n && f.find(a[r]) != f.end()){
                f[a[r++]]++;
            }
        }
        // cout<<l<<" "<<r<<endl;
        // r--;
        ans+=(r-l);
        f[a[l]]--;
        if(f[a[l]] == 0) f.erase(a[l]);
        l++;
        // r = l;
    }
    cout<<ans<<endl;
    return 0;
}
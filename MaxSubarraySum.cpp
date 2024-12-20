#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,a,b;
    cin>>n>>a>>b;
    vector<long long> arr(n);
    vector<long long> prefix(n+1,0);
    long long k = 0;
    long long s = 0;
    for(long long &x : arr){ cin>>x;s+=x;prefix[++k] = s;}
    long long ans = -1e18;
    multiset<long long> ms;
    for(long long i=a; i<=n; i++){
        if(i > b){
            ms.erase(ms.find(prefix[i-(b+1)]));
        }
        ms.insert(prefix[i-a]);
        ans = ans > (prefix[i] - *ms.begin()) ? ans : (prefix[i] - *ms.begin()) ;
    }
    cout<<ans;
    return 0;
}
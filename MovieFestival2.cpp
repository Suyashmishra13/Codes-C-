#include <bits/stdc++.h>
using namespace std;

// Wrong Method 
//Right Method -> MoviesFestivalTwo!

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    vector<pair<long long,long long>> se;
    for(long long i=0; i<n; i++){
        long long s,e;
        cin>>s>>e;
        se.push_back({e,s});
    }
    sort(se.begin(),se.end());
    long long ans = 0;
    vector<bool> vis(n,false);
    if(n == k) cout<<n<<endl;
    else{
    while(k--){
        long long end = -1;
        for(long long i=0; i<n; i++){
            if(!vis[i] && se[i].second >= end){
                ans++;
                end = se[i].first;
                vis[i] = true;
            }
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
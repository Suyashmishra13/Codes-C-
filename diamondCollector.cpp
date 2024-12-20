#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> d(n);
    for(int i=0; i<n; i++) cin>>d[i];
    sort(d.begin(),d.end());
    int r = 0;
    int maxleft[n];
    for(int l=0; l<n; l++){
        while(r<n && d[r]-d[l] <= k){
            r++;
        }
        maxleft[l] = r-l;
    }
    int maxfromright[n+1];
    maxfromright[n] = 0;
    for(int i=n-1; i>=0; i--){
        maxfromright[i] = max(maxfromright[i+1],maxleft[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans,maxleft[i] + maxfromright[i+maxleft[i]]);
    }
    cout<<ans<<endl;
    return 0;
}
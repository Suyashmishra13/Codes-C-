// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main(){
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>> a;
    for(ll i=0; i<n; i++){
        ll k;
        cin>>k;
        a.push_back({k,i});
    }
    sort(a.begin(),a.end());
    for(ll i=0; i<n; i++){
        ll curtg = x - a[i].first;
        ll first = 0;
        if(i == 0) first = 1;
        ll second = n-1;
        if(i == n-1) second = n-2;
        while(first < second){
            if(a[first].first + a[second].first > curtg){
                second--;
            }
            else if(a[first].first + a[second].first < curtg){
                first++;
            }
            else break;
        }
        if(a[first].second != a[second].second && a[first].second != a[i].second && a[second].second != a[i].second && ((a[first].first) + (a[second].first) + (a[i].first) == x)){
            cout<<a[first].second + 1 <<" "<<a[second].second + 1<<" "<<a[i].second+1<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
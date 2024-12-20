#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> se;
    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        se.push_back({e,s});
    }
    sort(se.begin(),se.end());
    multiset<int> ft;
    for(int i=0; i<k; i++) ft.insert(0);
    int nom = 0;
    for(int i=0; i<n; i++){
        auto it = ft.upper_bound(se[i].second);
        if(it == ft.begin()) continue;
        nom++;
        ft.erase(ft.find(*(--it)));
        ft.insert(se[i].first);
    }
    cout<<nom<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    set<int> city;
    set<int> tower;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        city.insert(x);
    }
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        tower.insert(x);
    }
    map<int,int> tc;
    for(int x: city){
        auto it = tower.lower_bound(x);
        auto itb = it;
        if(it == tower.begin()){
            tc[x] = *it;
        }
        else if(it == tower.end()){
            it--;
            tc[x] = *it;
        }
        else{
            itb--;
            int mark = x - *itb > *it - x ? *it : *itb;
            tc[x] = mark;
        }
    }
    int ans = 0;
    for(auto const &it : tc){
        ans = max(ans,abs(it.first - it.second));
    }
    cout<<ans<<endl;
    return 0;
}
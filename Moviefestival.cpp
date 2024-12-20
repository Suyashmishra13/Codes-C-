#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> time;
    for(int i=0; i<n; i++){
        int start,end;
        cin>>start>>end;
        time.push_back({end,start});
    }
    sort(time.begin(),time.end());
    int curend = time[0].first;
    int nom = 1;
    for(int i=0; i<n; i++){
        if(time[i].second >= curend){
            nom++;
            curend = time[i].first;
        }
    }
    cout<<nom<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    vector<pair<long long,long long>> tasks;
    for(long long i=0; i<n; i++){
        long long dur,dl;
        cin>>dur>>dl;
        tasks.push_back({dur,dl});
    }
    sort(tasks.begin(),tasks.end());
    long long cur = 0;
    long long reward = 0;
    for(long long i=0; i<n; i++){
        cur+=tasks[i].first;
        reward+=(tasks[i].second - cur);
    }
    cout<<reward<<endl;
    return 0;
}
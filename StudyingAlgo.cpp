#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> min(n);
    for(int i=0; i<n; i++){
        cin>>min[i];
    }
    sort(min.begin(),min.end());
    int i=0;
    int sum = 0;
    while(i<n && sum <= x){
        sum+=min[i++];
    }
    if(i == n) cout<<i<<endl;
    else cout<<i-1<<endl;
    return 0;
}
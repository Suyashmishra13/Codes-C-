#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<int> bales(n);
    for(int i=0; i<n; i++) cin>>bales[i];
    sort(bales.begin(),bales.end());
    while(q--){
        int start,end;
        cin>>start>>end;
        cout<<upper_bound(bales.begin(),bales.end(),end) - lower_bound(bales.begin(),bales.end(),start) <<endl;
    }
    return 0;
}
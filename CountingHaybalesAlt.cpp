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
    for(int &x : bales) cin>>x;
    sort(bales.begin(),bales.end());
    auto maxtomax = [&](int find){
        int low = 0;
        int high = n;
        while(low < high){
            int mid = (high+low)/2 ;
            if(find >= bales[mid]){
                low = mid+1;
            }
            else high = mid;
        }
        return low;
    };
    while(q--){
        int start,end;
        cin>>start>>end;
        cout<<maxtomax(end) - maxtomax(start-1)<<endl;
    }
    return 0;
}
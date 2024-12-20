#include <bits/stdc++.h>
using namespace std;

//Solving Still :

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    int n;
    cin>>n;
    vector<int> pos(n);
    for(int &x:pos) cin>>x;
    sort(pos.begin(),pos.end());
    int low = pos[0];
    int high = pos[n-1];
    int r = INT_MAX;
    while(low < high){
        int mid = (high+low)/2;
        if(isbetter(mid) < r){
            low = mid;
        }
        else high = mid+1;
    }
    return 0;
}
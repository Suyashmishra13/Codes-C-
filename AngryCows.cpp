#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("angry.in","r",stdin);
    freopen("angry.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> pos(n);
    for(int &x:pos) cin>>x;
    sort(pos.begin(),pos.end());
    int low = pos[0];
    int high = (pos[n-1] - pos[0] + 1 )/k;
    auto isPossible = [&](int mid,int nog){
        int countgrps = 0;
        int i = 0;
        while(i < n){
            int curele = pos[i];
            countgrps++;
            while(i < n && pos[i] - curele <= 2*mid){
                i++;
            }
        }
        return countgrps <= nog;
    };
    while(low < high){
        int mid = (high+low)/2;
        if(isPossible(mid,k)){
            high = mid;
        }
        else low = mid+1;
        if(low == high) break;
    }
    cout<<low<<endl;
    return 0;
}
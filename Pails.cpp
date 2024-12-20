#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    freopen("pails.in","r",stdin);
    int x,y,m;
    cin>>x>>y>>m;
    int ans = INT_MAX;
    for(int i=0; i<= m; i+=x){
        int target = m - i;
        while(target >= 0){
            if(target >= 0) ans = min(ans,target);
            target-=y;
            // if(target >= 0) ans = min(ans,target);
        }
    }
    freopen("pails.out","w", stdout);
    if(ans == INT_MAX) cout<<0;
    else cout<< m - ans;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("planting.in","r",stdin);
    freopen("planting.out","w",stdout);
    int n;
    cin>>n;
    vector<int> deg(n,0);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin>>x>>y;
        deg[--y]++;
        deg[--x]++;
    }
    vector<bool> vis(n,false);
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans,deg[i]);
    }
    cout<<ans+1<<endl;
    return 0;
}
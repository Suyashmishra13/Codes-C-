#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int ans = 0;
    vector<vector<char>> spotinfo(2*n,vector<char>(m));
    for(int i=0; i<2*n; i++){
        for(int j=0; j<m; j++){
            cin>>spotinfo[i][j];
        }
    }
    for(int i=0;i<m;i++){
        unordered_set<char> spottyinfo;
        int k = 1;
        for(int j=0; j<n; j++){
            spottyinfo.insert(spotinfo[j][i]);
        }
        for(int j=n; j<2*n; j++){
            if(spottyinfo.count(spotinfo[j][i]) > 0){
                k = 0;
                break;
            }
        }
        if(k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

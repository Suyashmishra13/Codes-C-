#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int>> forest(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char x;
            cin>>x;
            if(x == '.'){
                forest[i][j] = 0;
            }
            else {
                forest[i][j] = 1;
            }
        }
    }
    vector<vector<int>> prefix(n+1,vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + forest[i-1][j-1] - prefix[i-1][j-1];
        }
    }
    while(q--){
        int x1,y1, x2,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
        cout<<ans<<endl;
    }
    return 0;
}
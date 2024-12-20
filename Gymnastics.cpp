#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);
    int k,n;
    cin>>k>>n;
    vector<vector<int>> rankings(k,vector<int>(n));
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin>> rankings[i][j];
        }
    }
    vector<vector<int>> subspair(n+1,vector<int>(n+1,0));
    for(vector<int> x : rankings){
        for(int i=0; i<x.size(); i++){
            for(int j=i+1; j<x.size(); j++){
                subspair[x[i]][x[j]]++;
            }
        }
    }
    int ans = 0;
    for(vector<int> x : subspair){
        for(int y : x){
            if(y == k) ans++;
        }
    }
    cout<<ans;
    return 0;
}
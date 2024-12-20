#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main(){
    freopen("diamond.in","r",stdin);
    int n,k;
    cin>>n>>k;
    vector<int> sizeofdiamonds(n);
    set<int> myset;
    for(int i=0; i<sizeofdiamonds.size(); i++){
        cin>>sizeofdiamonds[i];
    }
    int fans = 0;
    for(int i=0; i<sizeofdiamonds.size(); i++){
        int ans = 0;
        for(int j=0; j<sizeofdiamonds.size(); j++){
            if(sizeofdiamonds[i] <= sizeofdiamonds[j] && sizeofdiamonds[j]-sizeofdiamonds[i]<=k){
                ans++;
            }
        }
        fans = max(fans,ans);
    }
    freopen("diamond.out","w",stdout);
    cout<<fans<<endl;
    return 0;
}
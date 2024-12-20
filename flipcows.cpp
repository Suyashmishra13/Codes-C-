#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("cowtip.in","r",stdin);
    freopen("cowtip.out","w",stdout);
    int n;
    cin>>n;
    vector<vector<char>> cow_state(n,vector<char>(n));
    for(int i=0 ;i<n; i++){
        for(int j=0; j<n; j++){
            char temp;
            cin>>temp;
            cow_state[i][j] = temp;
        }
    }
    int ans = 0;
    for (int i = n-1; i >=0; i--)
    {
        for(int j=n-1; j>=0; j--){
            if(cow_state[i][j] == '1'){
                for(int x=0; x<=i; x++){
                    for(int y=0; y<=j; y++){
                        if(cow_state[x][y] == '1'){
                            cow_state[x][y] = '0';
                        }
                        else{
                            cow_state[x][y] = '1';
                        }
                    }
                }
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
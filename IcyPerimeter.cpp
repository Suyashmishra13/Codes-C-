#include <bits/stdc++.h>
using namespace std;
int floodfill(long long x,long long y,vector<vector<bool>> &vis,vector<string> &mac,long long &curmem,long long &p){
    if(x < 0 || x >= mac.size() || y < 0 || y >= mac[0].length() || mac[x][y] != '#')
        return 0;
    else if(vis[x][y]) return 1;
    vis[x][y] = true;
    curmem++;
    int right = floodfill(x+1,y,vis,mac,curmem,p);
    int left = floodfill(x-1,y,vis,mac,curmem,p);
    int up = floodfill(x,y+1,vis,mac,curmem,p);
    int down = floodfill(x,y-1,vis,mac,curmem,p);
    p+=(4 - (left+right+up+down));
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("perimeter.in","r",stdin);
    freopen("perimeter.out","w",stdout);
    long long n;
    cin>>n;
    vector<string> mac(n);
    for(long long i=0; i<n; i++){
        cin>>mac[i];
    }
    long long m = mac[0].length();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    long long ans = 0;
    long long p = 0;
    for(long long i=0; i<n; i++){
        for(long long j=0; j<m; j++){
            if(!vis[i][j] && mac[i][j] == '#'){
                long long curcount = 0;
                long long peri = 0;
                floodfill(i,j,vis,mac,curcount,peri);
                if(curcount > ans){
                    ans = curcount;
                    p = peri;
                }
                else if(curcount == ans){
                    if(peri < p){
                        p = peri;
                    }
                }
            }
        }
    }
    cout<<ans<<" "<<p<<endl;
    return 0;
}
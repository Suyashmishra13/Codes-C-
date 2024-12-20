#include <bits/stdc++.h>
using namespace std;
void floodfill(int x,int y,vector<vector<int>> &elevatn,vector<vector<bool>> &vis,int D){
    if(x < 0 || x >= elevatn.size() || y < 0 || y >= elevatn[0].size() || vis[x][y])
        return;
    vis[x][y] = true;
    if(x+1 < elevatn.size() && abs(elevatn[x][y] - elevatn[x+1][y]) <= D) floodfill(x+1,y,elevatn,vis,D);
    if(x-1>= 0 && abs(elevatn[x][y] - elevatn[x-1][y]) <= D) floodfill(x-1,y,elevatn,vis,D);
    if(y+1 < elevatn[0].size() && abs(elevatn[x][y] - elevatn[x][y+1]) <= D) floodfill(x,y+1,elevatn,vis,D);
    if(y-1>=0 && abs(elevatn[x][y] - elevatn[x][y-1]) <= D) floodfill(x,y-1,elevatn,vis,D);
    return;
}
bool ispossible(int &minD,vector<vector<int>> &elevatn,vector<vector<int>> &waypt,int &x,int &y){
    int n = elevatn.size();
    int m = elevatn[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        floodfill(x,y,elevatn,vis,minD);
        bool ans = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(waypt[i][j]){
                    if(!vis[i][j]) {ans = false; break;}
                }
            }
        }
    return ans;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ccski.in","r",stdin);
    freopen("ccski.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> elevatn(n,vector<int>(m));
    vector<vector<int>> waypt(n,vector<int>(m));
    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>elevatn[i][j];
            low = min(low,elevatn[i][j]);
            high = max(high,elevatn[i][j]);
        }
    }
    int sx=0,sy=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>waypt[i][j];
            if(waypt[i][j]){
                sx = i;
                sy = j;
            }
        }
    }
    high-=low;
    low = 0;
    while(low <= high){
        int mid = (high + low)/2;
        if(ispossible(mid,elevatn,waypt,sx,sy)){
            high = mid-1;
        }
        else low = mid+1;
    }
    cout<<low<<endl;
    return 0;
}
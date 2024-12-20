#include <bits/stdc++.h>
using namespace std;
void floodfill(int x,int y,vector<vector<int>> &farm,vector<vector<bool>> &vis){
    if(x<0 || y<0 || x>= farm.size() || y>= farm.size() || farm[x][y] == 1 || vis[x][y])
        return;
    vis[x][y] = true;
    floodfill(x+1,y,farm,vis);
    floodfill(x-1,y,farm,vis);
    floodfill(x,y+1,farm,vis);
    floodfill(x,y-1,farm,vis);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,r;
    cin>>n>>k>>r;
    vector<vector<int>> farm(n,vector<int>(n,0));
    for(int i=0; i<r; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        farm[x1][y1] = 1;
        farm[x2][y2] = 1;
    }
    vector<pair<int,int>> start;
    for(int i=0; i<k; i++){
        int x,y;
        cin>>x>>y;
        start.push_back({x,y});
    }
    int pairs = 0;
    auto distant = [&](int fcow,int scow){
        int x1 = start[fcow].first;
        int y1 = start[fcow].second;
        int x2 = start[scow].first;
        int y2 = start[scow].second;
        farm[x1][y1] = 0;
        farm[x2][y2] = 0;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        floodfill(x1,y1,farm,vis);
        return vis[x2][y2];
    };
    for(int i=0; i<k; i++){
        for(int j=i+1; j<k; j++){
            if(distant(i,j)) pairs++;
        }
    }
    return 0;
}
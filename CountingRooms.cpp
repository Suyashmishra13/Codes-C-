#include <bits/stdc++.h>
using namespace std;
const int s = 1001;
bool visited[s][s];
char building[s][s];
void floodfill(int x,int y,int n,int m){
    if(x < 0 || x >= n || y<0 || y >= m  || visited[x][y] || building[x][y] == '#')
        return;
    visited[x][y] = true;
    floodfill(x+1,y,n,m);
    floodfill(x-1,y,n,m);
    floodfill(x,y+1,n,m);
    floodfill(x,y-1,n,m);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    // vector<vector<char>> building(n,vector<char>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin>>x;
            building[i][j] = x;
        }
    }
    int rooms = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && building[i][j] == '.'){
                rooms++;
                floodfill(i,j,n,m);
            }
        }
    }
    cout<<rooms<<endl;
    return 0;
}
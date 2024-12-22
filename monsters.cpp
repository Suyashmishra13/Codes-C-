#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ll int
#define pii pair<int, int>
int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
queue<pii> bfs;
char M[1001][1001];
int n,m;
int mdist[1001][1001];
int sdist[1001][1001];
pii path[1001][1001];
// revisited monsters problem from CSES set
bool possible(pii first,pii sec){
  if(sec.first >= n || sec.first < 0 || sec.second >= m || sec.second < 0 || M[sec.first][sec.second] == '#') return false;
  int distfirst = mdist[first.first][first.second];
  if(distfirst+1 < mdist[sec.first][sec.second]){
      mdist[sec.first][sec.second] = distfirst + 1;
      bfs.push(sec);
  }
  return true;
}
bool possibleforA(pii first,pii sec){
  if(sec.first >= n || sec.first < 0 || sec.second >= m || sec.second < 0 || M[sec.first][sec.second] == '#') return false;
  int distfirst = sdist[first.first][first.second];
  if(distfirst+1 < sdist[sec.first][sec.second]){
      sdist[sec.first][sec.second] = distfirst + 1;
      bfs.push(sec);
      path[sec.first][sec.second] = first;
  }
  return true;
}
void palgo(){
  while(!bfs.empty()){
    pii cur = bfs.front();
    bfs.pop();
    for(int i=0; i<4; i++){
      possible(cur,{cur.first + dx[i],cur.second+dy[i]});
    }
  }
  return;
}
bool fa = false;
pii fans = {-1,-1};
void palgoforA(){
  while(!bfs.empty()){
    pii cur = bfs.front();
    if(cur.first == 0 || cur.second == 0 || cur.first == n-1 || cur.second == m-1){
      if(sdist[cur.first][cur.second] < mdist[cur.first][cur.second]){
        fa = true;
        fans = cur;
        return;
      }
    }
    bfs.pop();
    for(int i=0; i<4; i++){
      possibleforA(cur,{cur.first + dx[i],cur.second+dy[i]});
    }
  }
  return;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    int sx,sy;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mdist[i][j] = INT_MAX;
            sdist[i][j] = INT_MAX;
            cin>>M[i][j];
            if(M[i][j] == 'A'){
              sdist[i][j] = 0;
              sx = i; sy = j;
            }
            if(M[i][j] == 'M'){
              bfs.push({i,j});
              mdist[i][j] = 0;
            }
        }
    }
    palgo();
    bfs.push({sx,sy});
    palgoforA();
    if(fa){
      cout<<"YES"<<endl;
      path[sx][sy] = {sx,sy};
      cout<<sdist[fans.first][fans.second]<<endl;
      string pathfinal = "";
      while(fans.first != sx || fans.second != sy){
          pii newfans = path[fans.first][fans.second];
          if(newfans.first + 1 == fans.first){
              pathfinal+="D";
          }
          else if(newfans.first -1 == fans.first){
              pathfinal+="U";
          }
          else if(newfans.second + 1 == fans.second){
              pathfinal+="R";
          }
          else pathfinal+="L";
          fans = newfans;
      }
      reverse(pathfinal.begin(),pathfinal.end());
      cout<< pathfinal <<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
    return 0;
}

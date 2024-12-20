#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<char>> maze(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int startx=-1,starty=-1;
    int cbx=-1,cby=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>maze[i][j];
            if(maze[i][j] == 'A'){
                startx = i;
                starty = j;
            }
            if(maze[i][j] == 'B'){
                cbx = i;
                cby = j;
            }
        }
    }
    vis[startx][starty] = true;
    vector<vector<pair<int,int>>> pred(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<int,int>> mq;
    mq.push({startx,starty});
    bool found = false;
    int dist = 0;
    while(!mq.empty()){
        int size = mq.size();
        while(size--){
            pair<int,int> cur = mq.front();
            mq.pop();
            vis[cur.first][cur.second] = true;
            if(maze[cur.first][cur.second] == 'B'){
                found = true;
                break;
            }
            if(cur.first+1 < n && maze[cur.first+1][cur.second] != '#' && !vis[cur.first+1][cur.second]){
                mq.push({cur.first+1,cur.second});
                vis[cur.first+1][cur.second] = true;
                pred[cur.first+1][cur.second].first = cur.first;
                pred[cur.first+1][cur.second].second = cur.second;
            }
            if(cur.second + 1 < m && maze[cur.first][cur.second+1] != '#' && !vis[cur.first][cur.second+1]){
                mq.push({cur.first,cur.second+1});
                vis[cur.first][cur.second+1] = true;
                pred[cur.first][cur.second+1].first = cur.first;
                pred[cur.first][cur.second+1].second = cur.second;
            }
            if(cur.first-1 >= 0 && maze[cur.first-1][cur.second] != '#' && !vis[cur.first-1][cur.second]){
                mq.push({cur.first-1,cur.second});
                vis[cur.first-1][cur.second] = true;
                pred[cur.first-1][cur.second].first = cur.first;
                pred[cur.first-1][cur.second].second = cur.second;
            }
            if(cur.second - 1>= 0 && maze[cur.first][cur.second-1] != '#' && !vis[cur.first][cur.second-1]){
                mq.push({cur.first,cur.second-1});
                vis[cur.first][cur.second-1] = true;
                pred[cur.first][cur.second-1].first = cur.first;
                pred[cur.first][cur.second-1].second = cur.second;
            }
            // mq.pop();
        }
        // if(found) break;
        // dist++;
    }
    if(pred[cbx][cby].first != -1 && pred[cbx][cby].second != -1){
        cout<<"YES"<<endl;
        string path = "";
        while(pred[cbx][cby].first != -1 && pred[cbx][cby].second != -1){
            dist++;
            int incbx = cbx;
            int incby = cby;
            cbx = pred[cbx][cby].first;
            cby = pred[incbx][incby].second; // here using cbx and cby would cause problems since i have already 
            if(cbx == incbx + 1) path+="D"; // changed both of those values here.
            if(cbx == incbx - 1) path+="U";
            if(cby == incby - 1) path+="L";
            if(cby == incby + 1) path+="R";
        }
        cout<<dist<<endl;
        reverse(path.begin(),path.end());
        for(char &x:path){
            if(x == 'L'){ x = 'R';}
            else if(x == 'R'){ x = 'L';}
            else if(x == 'D'){ x = 'U';}
            else if(x == 'U'){ x = 'D';}
        }
        cout<<path;
    }
    else{
        cout<<"NO";
    }
    return 0;
}
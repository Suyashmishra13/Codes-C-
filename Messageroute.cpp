#include <bits/stdc++.h>
using namespace std;
const int sze = 1e5+1;
// bool vis[sze];
vector<vector<int>> ans;
int curmin = INT_MIN;
void dfs(int cur,vector<int> graph[],int dest,vector<int> curpath={},int dist=0,int p=0){
    if(cur == dest){
        curpath.push_back(dest);
        if(ans.empty()){ 
            ans.push_back(curpath);
            curmin = dist;
        }
        else if(dist < curmin){
            ans.pop_back();
            ans.push_back(curpath);
            curmin = dist;
        }
        curpath.pop_back();
        return;
    }
    // vis[cur] = true;
    curpath.push_back(cur);
    for(int x : graph[cur]){
        if(x != p){
            dfs(x,graph,dest,curpath,dist+1,cur);
        }
    }
    curpath.pop_back();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[--a].push_back(--b);
        graph[b].push_back(a);
    }
    // dfs(0,graph,n-1);
    // if(curmin != INT_MIN){
    //     cout<<curmin<<endl;
    //     for(vector<int> x:ans){
    //         for(int y : x) cout<<y+1<<" ";
    //     }
    // }
    // else cout<<"IMPOSSIBLE";
    vector<int> pred(n);
    vector<int> dist(n,0);
    vector<bool> vis(n,false);
    queue<int> mq;
    mq.push(0);
    vis[0] = true;
    while(!mq.empty()){
        int cur = mq.front();
        mq.pop();
        for(int x : graph[cur]){
            if(!vis[x]){
                vis[x] = true;
                dist[x] = dist[cur] + 1;
                pred[x]= cur;
                mq.push(x);
            }
        }
    }
    if(dist[n-1]){
        cout<<dist[n-1]+1<<endl;
        pred[0] = -1;
        int cur = n-1;
        vector<int> order;
        order.push_back(n);
        while(cur != 0){
            order.push_back(pred[cur]+1);
            cur = pred[cur];
        }
        for(int i=order.size()-1; i>=0; i--) cout<<order[i]<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
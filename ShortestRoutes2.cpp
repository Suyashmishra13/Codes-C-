#include <bits/stdc++.h>
using namespace std;
struct tuples{
    long long a,b,w;
    tuples(long long f,long long s,long long weight) : a(f),b(s),w(weight){};
};
const long long big = 1e18;
long long dist[501][501];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m,q;
    cin>>n>>m>>q;
    vector<tuples> graph;
    while(m--){
        long long a,b,w;
        cin>>a>>b>>w;
        graph.push_back(tuples(a,b,w));
        if(!dist[a][b]){dist[a][b] = w;}
        else dist[a][b] = min(dist[a][b],w);
        if(!dist[b][a]){dist[b][a] = w;}
        else dist[b][a] = min(dist[b][a],w);
    }
    for(long long i=1; i<=n; i++){
            for(long long j=1; j<=n; j++){
                if(i == j) dist[i][j] = 0;
                else if(!dist[i][j]) dist[i][j] = big;
            }
        }
    for(long long k=1; k<=n; k++){
        for(long long i=1; i<=n; i++){
            for(long long j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    for(long long k=1; k<=n; k++){
        for(long long i=1; i<=n; i++){
            for(long long j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        if(dist[x][y]!=big){
            cout<<dist[x][y]<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}
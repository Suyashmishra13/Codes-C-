#include <bits/stdc++.h>
using namespace std;
vector<int> p;
vector<int> s;
struct DSU{
    int val;
    DSU(int x) : val(x){
        p.resize(val);
        s.resize(val,1);
        iota(p.begin(),p.end(),0);
    };
    int get(int val){
        if(val == p[val]) return val;
        else return p[val] = get(p[val]);
    }
    bool unite(int a,int b,int &comp,int &maxcomp){
        int x = get(a);
        int y = get(b);
        if(x == y) {return true;}
        if(s[x] > s[y]) swap(x,y);
        s[y]+=s[x];
        comp--;
        p[x] = y;
        maxcomp = max(maxcomp,s[y]);
        return false;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    int noc = n;
    int maxval = 1;
    for(int i=0; i<m; i++){
        // int l = n;
        int a,b;
        cin>>a>>b;
        --a,--b;
        dsu.unite(a,b,noc,maxval);
        cout<<noc<<" ";
        cout<<maxval<<endl;
    }
    vector<pair<int,int>> ans;

    return 0;
}
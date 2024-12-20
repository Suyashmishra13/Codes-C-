#include <bits/stdc++.h>
using namespace std;
struct DSU {
	vector<int> e;
	void init(int n) { e = vector<int>(n, -1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); };
	bool sameSet(int x, int y) { return get(x) == get(y); };
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<pair<int,pair<int,int>>> arr;
    for(int i=0; i<n-1; i++){
        int start,end,relevance;
        cin>>start>>end>>relevance;
        arr.push_back({relevance,{--start,--end}});
    }
    vector<pair<int,pair<int,int>>> queries;
    for(int i=0; i<q; i++){
        int k,video;
        cin>>k>>video;
        queries.push_back({k,{--video,i}});
    }
    vector<int> ans(q);
    sort(arr.begin(),arr.end(),greater<pair<int,pair<int,int>>>());
    sort(queries.begin(),queries.end(),greater<pair<int,pair<int,int>>>());
    int index = 0;
    DSU dsu;
    dsu.init(n);
    for(pair<int,pair<int,int>> x : queries){
        int curk = x.first;
        while(index < arr.size() && arr[index].first >= curk){
            dsu.unite(arr[index].second.first,arr[index].second.second);
            index++;
        }
        ans[x.second.second] = dsu.size(x.second.first) - 1;
    }
    for(int x: ans) cout<<x<<endl;
    return 0;
}
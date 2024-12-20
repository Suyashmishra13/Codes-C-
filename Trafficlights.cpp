#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    set<int > lights{0,n};
    multiset<int > gaps{n};
    for(int i=0; i<x; i++){
        int block;
        cin>>block;
        auto big = lights.upper_bound(block);
        auto small = big;
        small--;
        gaps.erase(gaps.find(*big-*small));
        gaps.insert(*big - block);
        gaps.insert(block-*small);
        lights.insert(block);

        auto ans = gaps.end();
        ans--;
        cout<<*ans<<" ";
    }
    return 0;
}
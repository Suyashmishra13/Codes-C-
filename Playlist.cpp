#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> songs(n);
    for(int &x : songs) cin>>x;
    int first = 0;
    int second = 1;
    int ans = 1;
    set<int> myset;
    myset.insert(songs[0]);
    while(first < n && second < n){
        if(myset.find(songs[second]) == myset.end()){
            myset.insert(songs[second++]);
            ans = max(ans,int(myset.size()));
        }
        else{
            ans = max(ans,int(myset.size())-1);
            while(first < n && !myset.empty() && myset.find(songs[second]) != myset.end()){
                myset.erase(songs[first++]);
                if(first == second) break;
            }
            myset.insert(songs[second]);
            second++;
        }
        ans = max(ans,int(myset.size()));
    }
    cout<<ans;
    return 0;
}
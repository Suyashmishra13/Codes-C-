#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(long long &x : a) cin>>x;
    multiset<long long> myset;
    for(long long i=0; i<n; i++){
        if(i+1 > k){
            auto it = myset.begin();
            long long copy = k/2;
            if(k%2 == 0) copy--;
            while(copy--){
                it++;
            }
            cout<<*(it)<<" ";
            myset.erase(myset.find(a[i-k]));
        }
        myset.insert(a[i]);
    }
    auto it = myset.begin();
            long long copy = k/2;
            if(k%2 == 0) copy--;
            while(copy--){
                it++;
            }
            cout<<*(it)<<" ";
    return 0;
}
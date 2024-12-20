#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    int n;
    cin>>n;
    vector<int> b1(n/2);
    vector<int>b2(n/2);
    set<int> nottaken;
    set<int> bessielower;
    set<int> bessiehigher;
    int first = 0;
    int second = 0;
    for(int i=0; i<n/2; i++) {
        cin>>b1[i];
        if(b1[i] >= n) first++;
        nottaken.insert(b1[i]);
    }
    for(int i=0; i<n/2; i++) {
        cin>>b2[i];
        if(b2[i] >= n)  second++;
        nottaken.insert(b2[i]);
    }
    for(int i=1; i<=2*n; i++){
        if(nottaken.find(i) == nottaken.end()){
            if((bessielower.size() < n/2)){
            bessielower.insert(i);
            }
            else{
                bessiehigher.insert(i);
            }
        }
    }
    sort(b2.rbegin(),b2.rend());
    int pts = 0;
    for(int i=0; i<n/2; i++){
        auto it = bessielower.upper_bound(b2[i]);
        if(it == bessielower.begin()) break;
        pts++;
        bessielower.erase(*(--it));
    }
    sort(b1.begin(),b1.end());
    for(int i=0; i<n/2; i++){
        auto it = bessiehigher.upper_bound(b1[i]);
        if(it == bessiehigher.end()) break;
        pts++;
        bessiehigher.erase(*(it));
    }
    cout<<pts<<endl;
    return 0;
}
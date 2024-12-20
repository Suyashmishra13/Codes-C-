#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    multiset<int> ms;
    while(n--){
        int x;
        cin>>x;
        if(ms.empty()){
            ms.insert(x);
        }
        else{
            auto it = ms.upper_bound(x);
            if(it == ms.end()){
                ms.insert(x);
            }
            else{
                ms.erase(ms.find(*it));
                ms.insert(x);
            }
        }
    }
    cout<<ms.size()<<endl;
    return 0;
}
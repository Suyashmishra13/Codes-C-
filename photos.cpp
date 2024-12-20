#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> bid(n);
    for(int i=0; i<n; i++) cin>>bid[i];
    unordered_map<int,int> m;
    for(int i=0; i<n; i++){
        m[bid[i]%2]++;
    }
    int even = m[0];
    int odd = m[1];
    while(odd>even){
            odd-=2;
            even+=1;
        }
    if(even > odd){
        cout<<(2*odd)+1<<endl;
    }
    else{
        cout<<2*odd<<endl;
    }
    return 0;
}
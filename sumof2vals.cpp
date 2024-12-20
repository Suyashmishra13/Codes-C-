#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;

int main(){
    long long n,x;
    cin>>n>>x;
    vector<pair<long long,long long>> arr;
    for(int i=0; i<n; i++){
        long long x;
        cin>>x;
        arr.push_back({x,i});
    }
    sort(arr.begin(),arr.end());
    long long first = 0;
    long long second = n-1;
    while(first < second){
        if(arr[first].first + arr[second].first > x){
            second--;
        }
        else if(arr[first].first + arr[second].first < x){
            first++;
        }
        else break;
    }
    if((arr[first].first + arr[second].first == x) && first != second){
        first = arr[first].second + 1;
        second = arr[second].second + 1;
        cout<<first<<" "<<second<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
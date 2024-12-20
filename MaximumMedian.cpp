#include <bits/stdc++.h>
using namespace std;
// bool isPossible(int valtbm,vector<int> arr,int k){
//     int half = 0;
//     for(int i=arr.size()/2; i<arr.size(); i++){
        
//     }
//     return arr[arr.size()/2] == valtbm;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    long long k;
    cin>>n>>k;
    vector<long long> arr(n);
    long long minele = INT_MAX;
    long long maxele = 0;
    for(long long i=0; i<n; i++){
        cin>>arr[i];
        minele = min(minele,arr[i]);
        maxele = max(maxele,arr[i]);
    }
    sort(arr.begin(),arr.end());
    long long low = 1;
    long long high = maxele + k;
    auto isPossible = [&](long long mid){
        long long half = 0;
    for(long long i=(arr.size()/2); i<arr.size(); i++){
        if(arr[i] - mid < 0) half += mid-arr[i];
    }
        return half <= k;
    };
    while(low<high){
        long long mid = low + (high-low+1)/2 ;
        if(isPossible(mid)){
            low = mid;
        }
        else high = mid-1;
    }
    cout<<low<<endl;
    return 0;
}
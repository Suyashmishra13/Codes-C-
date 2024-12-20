#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    cin>>n>>k;
    vector<long long> arr(n);
    for(long long &x:arr) cin>>x;
    long long t = 0;
    for(long long i=0; i<n; i++){
        t+=arr[i];
    }
    long long low = *max_element(arr.begin(),arr.end());
    long long high = t;
    auto ispossible = [&](long long maxsum,long long nos){
        long long count = 0;
        long long cursum = 0;
        long long i=0;
        while(i < n){
            count++;
            cursum = arr[i];
            while(i<n && cursum <= maxsum){
                i++;
                if(i >= n) break;
                cursum+=arr[i];
            }
        }
        return count <= nos;
    };
    while(low < high){
        long long mid = (low + high)/2;
        if(ispossible(mid,k)){
            high = mid;
        }
        else low = mid+1;
    }
    cout<<low<<endl;
    return 0;
}
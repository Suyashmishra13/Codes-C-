#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    long long int n,k;
    cin>>n>>k;
    vector<long long int> days(n);
    for(int i=0; i<n; i++){
        cin>>days[i];
    }
    long long int mincost = n + n*k;
    long long int forcost = 0;
    vector<bool> included(n,false);
    for(int i=0; i<n; i++){
        if(i+1 < n){
            if(days[i+1] - days[i]  <= k + 1){
                int start = i;
                while(i+1 < n && days[i+1] - days[i]  <= k + 1){
                    included[i] = true;
                    i++;
                }
                forcost += (days[i]-days[start] + 1 + k);
            }
            else{
                forcost += (k + 1);
                continue;
            }
        }
        else{
            if(included[n-2]){
                if(days[n-1]- days[n-2] + 1 >= k+1){
                    forcost += (days[n-1] - days[n-2] + 1 + k);
                }
            }
            else{
                forcost += (k+1);
            }
        }
    }
    mincost = min(mincost,forcost);
    cout<<mincost<<endl;
    return 0;
}
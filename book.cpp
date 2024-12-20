#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <unordered_map>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    vector<int> book_time(n);
    for(int i=0; i<n; i++) cin>>book_time[i];
    int first = 0;
    int second = 0;
    int sum = book_time[first]+book_time[second];
    int ans = 0;
    while(second < n){
        if(first == second){
            if(book_time[first] <= t) {
                ans=max(ans,1);
            }
            second++;
            if(second == n) break;
            sum = book_time[first] + book_time[second];
            if(sum <= t) ans=max(ans,second-first+1);
        }
        if(sum <= t){
            ans = max(ans,second-first+1);
            second++;
            if(second == n) break;
            sum+=book_time[second];
        }
        else if(sum > t){
            sum-=book_time[first];
            first++;
        }
        if(sum <= t && first != second) {
            ans = max(ans,second-first+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
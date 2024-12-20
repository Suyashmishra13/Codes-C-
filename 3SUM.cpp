#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int queries;
    cin>>n>>queries;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        int k;
        cin>>k;
        a[i].first = k;
        a[i].second = i;
    }
    sort(a.begin(),a.end());
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0; i<n; i++){
    for(int j=i+2; j<n; j++){
        int curtg = -a[i].first;
        int low = i;
        int high = j;
        while(low < high){
            if(a[low].first + a[high].first < curtg){
                low++;
            }
            else if(a[low].first + a[high].first > curtg) high--;
            else if(a[low].second != a[high].second && a[low].second != a[i].second && a[high].second != a[i].second && a[low].first + a[high].first == curtg){
            dp[a[i].second][a[j].second]++;
            }
        }
        // if(a[low].second != a[high].second && a[low].second != a[i].second && a[high].second != a[i].second && a[low].first + a[high].second + curtg == 0){
        //     dp[a[i].second][a[j].second]++;
        // }
    }
}
    // dp[i][j] represents 3 sum solution for indexes btw i and j;
    while(queries--){
        //code for each query
        int a,b;
        cin>>a>>b;
        if(a-b < 2) cout<<0<<endl;
        else cout<<dp[--a][--b]<<endl;
    }
    return 0;
}

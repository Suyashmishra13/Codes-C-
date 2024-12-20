#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> every;
    for(int i=0; i<n; i++){
        int arr,des;
        cin>>arr>>des;
        every.push_back({arr,0,i});
        every.push_back({des,1,i});
    }
    sort(every.begin(),every.end());
    vector<int> rooms;
    for(int i=n; i>0; i--) rooms.push_back(i);
    vector<int> assigned(n);
    int currooms = 0;
    int maxroom = 0;
    for(vector<int> x: every){
        if(x[1] == 0){
            currooms++;
            maxroom = max(maxroom,currooms);
            assigned[x[2]] = rooms.back();
            rooms.pop_back();
        }
        else{
            currooms--;
            rooms.push_back(assigned[x[2]]);
        }
    }
    cout<<maxroom<<endl;
    for(int i=0; i<n; i++) cout<<assigned[i]<<" ";
    return 0;
}

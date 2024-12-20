#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int &x : nums) cin>>x;
    stack<int> nsmal;
    for(int i=0; i<n; i++){
        if(nsmal.empty()){
            cout<<i<<" ";
            nsmal.push(i);
        }
        else if(nums[i] > nums[nsmal.top()]){
            cout<<nsmal.top()+1<<" ";
            nsmal.push(i);
        }
        else{
            while(!nsmal.empty() && nums[nsmal.top()] >= nums[i]){
                nsmal.pop();
            }
            if(nsmal.empty()) cout<<"0 ";
            else cout<<nsmal.top()+1<<" ";
            nsmal.push(i);
        }
    }
    return 0;
}
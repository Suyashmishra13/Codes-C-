#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
void swap(vector<int> &heights,int left,int &right,int &swaps,unordered_map<int,int> &start){
    swaps++;
    int newpos = start[heights[left]];
    int k = heights[newpos];
    heights[newpos] = heights[right];
    heights[right] = k;
    start[heights[newpos]] = newpos;
    start[heights[right]] = newpos+1;
    right = newpos;
}
void swapend(vector<int> &heights,int right,int &left,int &swaps,unordered_map<int,int> &ends){
    swaps++;
    int newpos = ends[heights[right]];
    int k = heights[newpos];
    heights[newpos] = heights[left];
    heights[left] = k;
    ends[heights[newpos]] = newpos;
    ends[heights[left]] = newpos-1;
    left = newpos;
}
int main(){
    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);
    int n;
    cin>>n;
    vector<int> heights(n);
    unordered_map<int,int> start,ends;
    int swaps = 0;
    int bpos = -1;
    for(int i=0; i<n; i++) {
        cin>>heights[i];
        if(i == 0 && heights[0] < heights[1]) bpos = 1;
        if(i != 0 && i != 1 && heights[i] < heights[i-1]) bpos = i;
        if(start.find(heights[i]) == start.end()){
            start[heights[i]] = i;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(ends.find(heights[i]) == ends.end()) ends[heights[i]] = i;
    }
    // cout<<bpos<<endl;
    bool smol = true;
    if(bpos+1 < n && heights[bpos] < heights[bpos+1]) {smol = false;}
    if(smol){
    int k = bpos-1;
    while(heights[k] > heights[bpos]){
        swap(heights,k,bpos,swaps,start);
        k = bpos-1;
    }
    }
    else{
        // cout<<"AAya"<<endl;
        for(int i=0; i<n; i++){
            if(i+1 < n && heights[i] > heights[i+1]) bpos = i;
        }
        if(bpos != -1){
        int k = bpos+1;
        while(heights[bpos] > heights[k]){
        swapend(heights,k,bpos,swaps,ends);
        k = bpos+1;
        // cout<<heights[bpos]<<" "<<heights[k]<<endl;
        if(k >= n) break;
        }
        }
    }
    cout<<swaps<<endl;
    // for(int x: heights) cout<<x<<" ";
    return 0;
}
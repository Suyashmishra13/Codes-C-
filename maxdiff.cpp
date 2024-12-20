#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
using namespace std;
long long Allpossiblities(int index,vector<long long> weight,long long sum1,long long sum2,long long &ans){
    if(index == weight.size()){
        return abs(sum1-sum2);
    }
    return min(Allpossiblities(index+1,weight,sum1+weight[index],sum2,ans),Allpossiblities(index+1,weight,sum1,sum2+weight[index],ans));
}
int main(){
    int n;
    cin>>n;
    vector<long long> weights(n);
    for(auto it : weights){
        cin>>it;
    }
    long long ans = 0;
    cout<<Allpossiblities(0,weights,0,0,ans)<<endl;
    return 0;
}
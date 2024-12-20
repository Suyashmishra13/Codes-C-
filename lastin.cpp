#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("notlast.in","r",stdin);
    freopen("notlast.out","w",stdout);
    string possible[] = {"Bessie","Maggie","Elsie","Henrietta","Gertie","Daisy","Annabelle"};
    int n;
    cin>>n;
    vector<string> name(n);
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin>>name[i];
        cin>>p[i];
    }
    map<string,int> s;
    for(int i=0; i<n; i++){
        s[name[i]]+=p[i];
    }
    if(s.size() < 7){
        for(int i=0;i<7; i++){
            if(s.find(possible[i]) == s.end()){
                s[possible[i]] = 0;
            }
        }
    }
    vector<int> vals;
    for(auto x : s){
        vals.push_back(x.second);
    }
    sort(vals.begin(),vals.end());
    int ansval = -1;
    for(int i=0;i<vals.size()-1; i++){
        if(vals[i] < vals[i+1]){
            ansval = vals[i+1];
            break;
        }
    }
    string ans = "";
    int k = 0;
    for(auto x : s){
        if(x.second == ansval){
            if(k){
                k++; break;
            }
            ans+=x.first;
            k++;
        }
    }
    if(ansval == -1) cout<<"Tie"<<endl;
    else if(k == 1) cout<<ans<<endl;
    else cout<<"Tie"<<endl;
    return 0;
}

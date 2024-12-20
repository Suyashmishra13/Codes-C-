#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    vector<string> p = {"BG", "BR", "BY", "GR", "GY", "RY"};
    while(test--){
        int n,q;
        cin>>n>>q;
        vector<string> city(n);
        for(int i=0; i<n; i++){
            string x;
            cin>>x;
            sort(x.begin(),x.end());
            city[i] = x;
        }
        while(q--){
            int start,end;
            cin>>start>>end;
            start--;end--;
            if(city[start][0] == city[end][0] || city[start][1] == city[end][0] || city[start][1] == city[end][0] || city[start][1] == city[end][0]){
                cout<<abs(start-end)<<endl;
                continue;
            }
            else{
                vector<bool> vis(6,false);
                vis[lower_bound(p.begin(),p.end(),city[start])-p.begin()] = true;
                vis[lower_bound(p.begin(),p.end(),city[end])-p.begin()] = true;
                int ns = start;
                while(ns < end && vis[lower_bound(p.begin(),p.end(),city[ns]) - p.begin()]){
                    ns++;
                }
                int es = end;
                while(es > start && vis[lower_bound(p.begin(),p.end(),city[es])-p.begin()]) es--;
                if((start < ns && end > ns) || (start < es && end > es)){
                    cout<<abs(start-end)<<endl;
                    continue;
                }
                int left = 0;
                while(left < start && vis[lower_bound(p.begin(),p.end(),city[left])-p.begin()]) left++;
                int right = n-1;
                while(right > end && vis[lower_bound(p.begin(),p.end(),city[right])-p.begin()]) right--;
                if(left < start){
                    cout<<abs(start-left) + abs(end-left)<<endl;
                    continue;
                }
                else if(right > end){
                    cout<<abs(start-right) + abs(end - right)<<endl;
                    continue;
                }
                cout<<-1<<endl;
            }
        }
    }
    return 0;
}
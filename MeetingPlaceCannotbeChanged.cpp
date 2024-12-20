#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<double,double>> pv(n);
    for(pair<double,double> &i : pv){
        cin>>i.first;
    }
    for(pair<double,double> &i : pv){
        cin>>i.second;
    }
    sort(pv.begin(),pv.end());
    double low = 0;
    double high = 2e9;
    double prc = 1e-7;
    auto ispossible = [&](double meettime){
        double rangep = pv[0].first + (pv[0].second * meettime);
        double rangen = pv[0].first - (pv[0].second * meettime);
        bool met = true;
        for(int i=1; i<n; i++){
            double curtimep = ((pv[i].first) + (double(pv[i].second)*meettime));
            double curtimen = ((pv[i].first)  - (double(pv[i].second)*meettime));
            rangen = curtimen < rangen ? rangen : curtimen;
            rangep = curtimep > rangep ? rangep : curtimep;
            if(rangep < rangen) {
                met = false;
                break;
            }
        }
        return met;
    };
    while(high - low > prc){
        double mid = (low + high)/2;
        if(ispossible(mid)){
            high = mid;
        }
        else low = mid;
    }
    cout<<fixed<<setprecision(6)<<low<<endl;
    return 0;
}
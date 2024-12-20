#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int n;
    cin >> n;

    vector<string> cows = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };
    sort(cows.begin(),cows.end());

    unordered_map<string, int> m;
    vector<string> ans;

    for (int i = 0; i < 8; i++) {
        m[cows[i]] = i;
    }
    vector<pair<string,string>> rel;

    for (int i = 0; i < n; i++) {
        string first, must, be, milked, beside, second;
        cin >> first >> must >> be >> milked >> beside >> second;
        rel.push_back({first,second});
    }
    while(next_permutation(cows.begin(),cows.end())){
        bool found = true;
        for(auto p : rel){
            auto a = find(cows.begin(),cows.end(),p.first);
            auto b = find(cows.begin(),cows.end(),p.second);
            if(abs(a-b) != 1) found = false;
        }
        if(found) break;
    }
    for(string x : cows) cout<<x<<endl;
    return 0;
}

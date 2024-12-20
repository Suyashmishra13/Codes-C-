#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> perm(n);
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < n; i++)
        cin >> perm[i];
    // vector<pair<int,pair<int,int>>> worm;
    map<pair<int, int>, int> path;
    for (int i = 0; i < m; i++)
    {
        int a, b, p;
        cin >> a >> b >> p;
        path[{a, b}] = p;
        path[{b, a}] = p;
        high = max(high, p);
        low = min(low, p);
    }
    // sort(worm.begin(),worm.end(),greater<pair<int,pair<int,int>>>());
    int o = 1;
    while (o < n + 1)
    {
        if (o == perm[o - 1])
        {
            o++;
        }
        else
            break;
    }
    if (o == n + 1)
    {
        cout << "-1" << endl;
        return 0;
    }
    auto ispossible = [&](int val)
    {
        // for(int i=0; i<worm.size(); i++){
        //     if(worm[i].first >= val){
        //         // path.push_back({worm[i].second.first,worm[i].second.second});
        //         path[{worm[i].second.first,worm[i].second.second}]++;
        //         path[{worm[i].second.second,worm[i].second.first}]++;
        //     }
        //     else break;
        // }
        vector<int> copy = perm;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (copy[j] < copy[i] && path.find({j + 1, i + 1}) != path.end() && path[{j + 1, i + 1}] >= val)
                {
                    swap(copy[i],copy[j]);
                    // cout<<copy[i]<<" "<<copy[j]<<endl;
                }
            }
        }
        for (int i = 0; i < copy.size(); i++)
        {
            if (copy[i] != i + 1)
                return false;
        }
        return true;
    };
    int valid = 0;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (ispossible(mid))
        {
            valid = mid;
            low = mid + 1;
        }
        else
            high = mid;
    }
    cout << valid;
    return 0;
}
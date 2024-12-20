#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin>>n;
    vector<long long> a(n);
    for(long long &x : a) cin>>x;
    stack<long long> ms;
    vector<long long> left(n,-1);
    vector<long long> right(n,-1);
    for(long long i=0; i<n; i++){
            while(!ms.empty() && a[ms.top()] >= a[i]){
                ms.pop();
            }
        left[i] = ms.empty() ? 0 : ms.top()+1;
        ms.push(i);
    }
    while(!ms.empty()){ ms.pop();}
   for(long long i=n-1; i>=0; i--){
            while(!ms.empty() && a[ms.top()] >= a[i]){
                ms.pop();
            }
        right[i] = ms.empty() ? n-1 : ms.top()-1;
        ms.push(i);
    }
    long long ans = INT_MIN;
    for(long long i=0; i<n; i++){
        ans = max(ans,(right[i] - left[i]+1)*a[i]);
    }
    cout<<ans;
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    stack<int> ms;
    vector<int> left(n), right(n);

    // Calculate left limits
    for(int i = 0; i < n; i++){
        while(!ms.empty() && a[ms.top()] >= a[i]){
            ms.pop();
        }
        left[i] = ms.empty() ? 0 : ms.top() + 1;
        ms.push(i);
    }

    while(!ms.empty()) ms.pop(); // Clear the stack for right limit calculation

    // Calculate right limits
    for(int i = n - 1; i >= 0; i--){
        while(!ms.empty() && a[ms.top()] >= a[i]){
            ms.pop();
        }
        right[i] = ms.empty() ? n - 1 : ms.top() - 1;
        ms.push(i);
    }

    // Print left and right limits for debugging
    for(int x : left) cout << x << " ";
    cout << endl;
    for(int x : right) cout << x << " ";
    cout << endl;

    // Calculate the maximum area
    int max_area = 0;
    for(int i = 0; i < n; i++){
        int width = right[i] - left[i] + 1;
        int area = a[i] * width;
        max_area = max(max_area, area);
    }
    cout << max_area << endl;

    return 0;
}

*/
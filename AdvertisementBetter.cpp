#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> heights(n);
    for (ll &h : heights) {
        cin >> h;
    }

    stack<int> mono_stack;
    vector<ll> left(n), right(n), area(n);

    // Calculate left limits
    for (int i = 0; i < n; i++) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            mono_stack.pop();
        }
        left[i] = (mono_stack.empty() ? 0 : mono_stack.top() + 1);
        mono_stack.push(i);
    }

    // Clear stack for reuse
    while (!mono_stack.empty()) {
        mono_stack.pop();
    }

    // Calculate right limits
    for (int i = n - 1; i >= 0; i--) {
        while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
            mono_stack.pop();
        }
        right[i] = (mono_stack.empty() ? n - 1 : mono_stack.top() - 1);
        mono_stack.push(i);
    }

    // Calculate areas and find max
    ll max_area = 0;
    for (int i = 0; i < n; i++) {
        area[i] = heights[i] * (right[i] - left[i] + 1);
        max_area = max(max_area, area[i]);
    }

    cout << max_area << endl;
}

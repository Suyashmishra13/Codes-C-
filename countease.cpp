#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    // Create a sorted version of the list
    vector<int> sorted_heights = heights;
    sort(sorted_heights.begin(), sorted_heights.end());

    // Count the number of misplaced elements
    int swaps = 0;
    for (int i = 0; i < n; ++i) {
        if (heights[i] != sorted_heights[i]) {
            ++swaps;
        }
    }

    // The number of swaps needed is one less than the number of misplaced elements
    // because each swap fixes two elements
    cout << swaps - 1 << endl;

    return 0;
}

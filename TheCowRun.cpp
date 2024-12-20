#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> pos(n);
	for (int i = 0; i < n; i++) { cin >> pos[i]; }

	sort(pos.begin(), pos.end());

	/*
	 * dp[i][j][k] = min cost of visiting all cows within the range
	 * i = left endpoint (inclusive)
	 * j = right endpoint (inclusive)
	 * k (0/1) = current side
	 */
	vector<vector<vector<int>>> dp(
	    n + 1, vector<vector<int>>(n + 1, vector<int>(2, INT32_MAX)));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; j++) {
			if (i == j) {
				dp[i][j][0] = abs(pos[i]) * n;
				dp[i][j][1] = abs(pos[j]) * n;
			} else {
				// the number of cows which the cost is inflicted upon
				int remaining = n - (j - i);

				// consider if we want to go to the same or opposite side
				if (i < n) {
					dp[i][j][0] = min(
					    dp[i + 1][j][0] +
					        (abs(pos[i + 1] - pos[i]) * remaining),
					    dp[i + 1][j][1] + (abs(pos[j] - pos[i]) * remaining));
				}

				if (j > 0) {
					dp[i][j][1] = min(
					    dp[i][j - 1][1] +
					        (abs(pos[j - 1] - pos[j]) * remaining),
					    dp[i][j - 1][0] + (abs(pos[j] - pos[i]) * remaining));
				}
			}
		}
	}

	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
}
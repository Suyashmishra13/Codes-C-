#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define pi pair<int, int>
#define f first
#define mp make_pair
#define s second

ll dp[100001][101];
const ll MOD = (10e8) + 7;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int arr[n];
	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	if (arr[0] == 0) {
		fill(dp[0], dp[0] + 101, 1);
	} else {
		dp[0][arr[0]] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (arr[i] == 0) {
            // if arr[i] = 0 then we count the number of ways we could have reached here and since eace state is possible
            // we check for j=1 to m although checking only for the prev element of j
			for (int j = 1; j <= m; j++) {
				dp[i][j] += dp[i - 1][j];
				if (j - 1 > 0) dp[i][j] += dp[i - 1][j - 1];
				if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] %= MOD;
			}
		} else {
            // just update the current state with the previous possibilities
			dp[i][arr[i]] += dp[i - 1][arr[i]];
			if (arr[i] - 1 > 0) dp[i][arr[i]] += dp[i - 1][arr[i] - 1];
			if (arr[i] + 1 <= m) dp[i][arr[i]] += dp[i - 1][arr[i] + 1];
			dp[i][arr[i]] %= MOD;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		ans += dp[n - 1][i];
		ans %= MOD;
	}
	cout << ans;
}
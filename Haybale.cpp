#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> dif(n);
	// read input and build difference array
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		dif[--l]++; // increment from where it starts
		if(r <= n-1) dif[r]--; //decrement one after from where it ends
	}
	int cursum = 0;
	for(int i=0; i<n; i++){
	    cursum += dif[i];
	    dif[i] = cursum;
	}
	sort(dif.begin(),dif.end());
	cout<<dif[n/2]<<endl;
	return 0;
}
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
	int city_num, flight_num;
	std::cin >> city_num >> flight_num;

	vector<vector<int>> flights(city_num);
	vector<vector<int>> back_edge(city_num);
	for (int i = 0; i < flight_num; i++) {
		int a, b;
		std::cin >> a >> b;
		flights[--a].push_back(--b);
		back_edge[b].push_back(a);
	}

	// Use Kahn's algorithm to do a topological sort
	vector<int> in_degree(city_num);
	for (const vector<int> &nodes : flights) {
		for (int node : nodes) { in_degree[node]++; }
	}

	std::queue<int> queue;
	for (int i = 0; i < city_num; i++) {
		if (in_degree[i] == 0) { queue.push(i); }
	}
	vector<int> top_sort;
	while (!queue.empty()) {
		int curr = queue.front();
		queue.pop();
		top_sort.push_back(curr);
		for (int next : flights[curr]) {
			if (--in_degree[next] == 0) { queue.push(next); }
		}
	}

	// Compute the dist array in topological order
	vector<int> parent(city_num, -1);
	vector<int> dist(city_num, INT32_MIN);
	dist[0] = 1;
	for (int i = 0; i < top_sort.size(); i++) {
		int b = top_sort[i];
		for (int prev : back_edge[b]) {
			if (dist[prev] + 1 > dist[b]) {
				dist[b] = dist[prev] + 1;
				parent[b] = prev;
			}
		}
	}

	if (dist[city_num - 1] < 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		// dist[city_num - 1] denotes the length of the longest path
		// ending at the final city. i.e. Lehmälä
		cout << dist[city_num - 1] << endl;

		// Begin from the final city, trace the parent pointer
		// to construct the entire path backward
		int at = city_num - 1;
		vector<int> route;
		while (parent[at] != -1) {
			route.push_back(at);
			at = parent[at];
		}
		route.push_back(0);

		// Print the route in the correct order
		std::reverse(route.begin(), route.end());
		for (int i = 0; i < route.size() - 1; i++) {
			cout << route[i] + 1 << ' ';
		}
		cout << route.back() + 1 << endl;
	}
}
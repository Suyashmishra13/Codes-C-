#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// BeginCodeSnip{DSU}
class DSU {
  private:
	vector<int> parent;
	vector<int> size;

  public:
	DSU(int size) : parent(size), size(size, 1) {
		for (int i = 0; i < size; i++) { parent[i] = i; }
	}

	int get_top(int n) {
		return parent[n] == n ? n : (parent[n] = get_top(parent[n]));
	}

	bool link(int n1, int n2) {
		n1 = get_top(n1);
		n2 = get_top(n2);
		if (n1 == n2) { return false; }
		if (size[n2] > size[n1]) { return link(n2, n1); }
		parent[n2] = n1;
		size[n1] += size[n2];
		return true;
	}
};
// EndCodeSnip

struct Wormhole {
	int c1, c2;
	int width;
};

bool operator<(const Wormhole &w1, const Wormhole &w2) {
	return w1.width < w2.width;
}

int main() {
	std::ifstream read("wormsort.in");
	int cow_num;
	int wormhole_num;
	read >> cow_num >> wormhole_num;

	vector<int> cows(cow_num);
	for (int &c : cows) {
		read >> c;
		c--;  // make the cows 0-indexed
	}

	int max_width = 0;
	vector<Wormhole> wormholes(wormhole_num);
	for (Wormhole &w : wormholes) {
		read >> w.c1 >> w.c2 >> w.width;
		w.c1--;
		w.c2--;
		max_width = std::max(max_width, w.width);
	}

	std::sort(wormholes.begin(), wormholes.end());

	int wormhole_at = wormhole_num;
	DSU dsu(cow_num);
	for (int i = 0; i < cow_num; i++) {
		while (dsu.get_top(i) != dsu.get_top(cows[i])) {
			wormhole_at--;
			dsu.link(wormholes[wormhole_at].c1, wormholes[wormhole_at].c2);
		}
	}

	std::ofstream("wormsort.out")
	    << (wormhole_at == wormhole_num ? -1 : wormholes[wormhole_at].width)
	    << endl;
}
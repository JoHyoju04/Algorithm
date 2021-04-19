#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef long long ll;
ll ans, s;
vector<ll> a;
vector<int> adj[300001];

void go(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		if (adj[v].size() != 1) go(v, u);
		ans += abs(a[v]);
		a[u] += a[v], a[v] = 0;
	}
}

ll solution(vector<int> A, vector<vector<int>> edges) {
	for (int i : A) a.push_back((ll)i);
	for (auto i : edges) {
		adj[i[0]].push_back(i[1]);
		adj[i[1]].push_back(i[0]);
	}
	for (ll i : a) s += i;
	if (s != 0) return -1;
	go(0, -1);
	return ans;
}
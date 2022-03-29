#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

struct Info {
	double val;
	int idx, cnt;
	bool operator < (const Info& i) const {
		return val < i.val;
	}
};

double sol(vector<double>& v, int m) {
	int n = v.size();
	priority_queue<Info> PQ;
	for (int i = 0; i < n; i++) {
		PQ.push({ v[i], i, 1 });
	}
	double mn = *min_element(v.begin(), v.end());
	double ret = PQ.top().val - mn;
	for (int i = 0; i < m; i++) {
		auto [val, idx, cnt] = PQ.top(); PQ.pop();
		val = v[idx] / ++cnt;
		PQ.push({ val, idx, cnt });
		mn = min(mn, val);
		ret = min(ret, PQ.top().val - mn);
	}
	return ret;
}

int main() {
	fastio;
	int n; cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	int m; cin >> m;
	cout << fixed << setprecision(12) << sol(v, m) << '\n';
}
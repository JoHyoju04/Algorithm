/*트리의 지름 :
1. 트리에서 임의의 정점 x를 잡는다.
2. 정점x에서 가장 먼 점점 y를 찾는다.
3. 정멎 y에서 가장 먼 정점 z를 찾는다.
트리의 지름은 정점 y와 정점z를 연결하는 경로다.
*/
#include<iostream>
#include<vector>
#include<utility>
using namespace std;
#define MAX 10001

int N, a, b, c, x, ans;
vector<pair<int, int> > node[MAX];

void dfs(int w, int cur, int prev = -1) {
	if (ans < w) {
		ans = w;
		x = cur;
	}
	for (int i = 0; i < node[cur].size(); i++) {
		int next = node[cur][i].first;
		int d = node[cur][i].second;
		if (next == prev) continue;
		dfs(w + d, next, cur);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		node[a].push_back(make_pair(b, c));
		node[b].push_back(make_pair(a, c));
	}
	dfs(0, 1);
	ans = 0;
	dfs(0, x);
	cout << ans;
}
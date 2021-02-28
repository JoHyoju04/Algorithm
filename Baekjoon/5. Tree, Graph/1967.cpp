/*Ʈ���� ���� :
1. Ʈ������ ������ ���� x�� ��´�.
2. ����x���� ���� �� ���� y�� ã�´�.
3. ���� y���� ���� �� ���� z�� ã�´�.
Ʈ���� ������ ���� y�� ����z�� �����ϴ� ��δ�.
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
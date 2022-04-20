#include <iostream>
#include <vector>
using namespace std;

int N, maxnode, maxdist;

vector<pair<int, int> > graph[10001];
bool visited[10001];

void dfs(int cur, int dist) {
	if (maxdist < dist) {//���࿡ �̹������� �Ÿ��� ���� �� �Ÿ����.
		maxdist = dist;//�̹� �Ÿ��� ���� �� �Ÿ���� �ֱ�.
		maxnode = cur;//�̹� ��尡 ���� �� ����� �ֱ�.
	}

	visited[cur] = true; //cur�� ��� �湮�޴ٰ� �ֱ�.
	for (int x = 0; x < graph[cur].size(); x++) {//cur�� ����Ǿ��ִ� ���� Ž��.
		int ncur = graph[cur][x].first;//cur�� ��忡�� �� �� �ִ� ncur���.
		int ndist = graph[cur][x].second + dist;// cur���� �Ÿ� + cur ~ ncur �Ÿ�.
		if (!visited[ncur]) dfs(ncur, ndist);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int s, e, v;
	cin >> N;
	for (int x = 0; x < N - 1; x++) {
		cin >> s >> e >> v;
		graph[s].push_back({ e,v });//���� ����. ����� �׷���.
		graph[e].push_back({ s,v });//���� ����.
	}
	dfs(1, 0);//��Ʈ ���(1)������ ���� �� ���� ã��. 
	for (int i = 0; i <= N; i++) {
		visited[i] = 0;
	}
	maxdist = 0;//���� Ž���̴� maxdist�� �ʱ�ȭ.
	dfs(maxnode, 0);//1������ ���� �� ���� ã��.
	cout << maxdist;
	return 0;
}

/*Ʈ���� ���� :
1. Ʈ������ ������ ���� x�� ��´�.
2. ����x���� ���� �� ���� y�� ã�´�.
3. ���� y���� ���� �� ���� z�� ã�´�.
Ʈ���� ������ ���� y�� ����z�� �����ϴ� ��δ�.

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
*/
#include <iostream>
#include <vector>
using namespace std;

int N, maxnode, maxdist;

vector<pair<int, int> > graph[10001];
bool visited[10001];

void dfs(int cur, int dist) {
	if (maxdist < dist) {//만약에 이번까지의 거리가 가장 먼 거리라면.
		maxdist = dist;//이번 거리를 가장 먼 거리라고 넣기.
		maxnode = cur;//이번 노드가 가장 먼 노드라고 넣기.
	}

	visited[cur] = true; //cur번 노드 방문햇다고 넣기.
	for (int x = 0; x < graph[cur].size(); x++) {//cur에 연결되어있는 노드들 탐색.
		int ncur = graph[cur][x].first;//cur번 노드에서 갈 수 있는 ncur노드.
		int ndist = graph[cur][x].second + dist;// cur까지 거리 + cur ~ ncur 거리.
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
		graph[s].push_back({ e,v });//간선 연결. 양방향 그래프.
		graph[e].push_back({ s,v });//간선 연결.
	}
	dfs(1, 0);//루트 노드(1)번에서 가장 먼 곳을 찾기. 
	for (int i = 0; i <= N; i++) {
		visited[i] = 0;
	}
	maxdist = 0;//새로 탐색이니 maxdist를 초기화.
	dfs(maxnode, 0);//1번에서 가장 먼 곳을 찾기.
	cout << maxdist;
	return 0;
}

/*트리의 지름 :
1. 트리에서 임의의 정점 x를 잡는다.
2. 정점x에서 가장 먼 점점 y를 찾는다.
3. 정멎 y에서 가장 먼 정점 z를 찾는다.
트리의 지름은 정점 y와 정점z를 연결하는 경로다.

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
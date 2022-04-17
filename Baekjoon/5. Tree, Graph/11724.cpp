#include <iostream>
#include <vector>
using namespace std;

bool visited[1001];
vector<int> graph[1001];

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
		if (!visited[next]) dfs(next);
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int answer = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			answer++;
		}
	}

	cout << answer;

	return 0;
}
/*
< 1753 : 최단경로 >
*/
#include <iostream>
#include<vector>
#include<queue>
#define MAX_VERTICES 20010
#define INF 987654321
using namespace std;
int V, E, K;;
vector<pair<int, int>> graph[MAX_VERTICES];
vector<int> dist(MAX_VERTICES, INF);

void shortestPath(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -1 * pq.top().first;
		int hear = pq.top().second;
		pq.pop();
		if (dist[hear] < cost) continue;
		for (int i = 0; i < graph[hear].size(); i++) {
			int next = graph[hear][i].first;
			int nextDist = cost + graph[hear][i].second;
			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push({ -1 * nextDist,next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		graph[from].push_back({ to,val });
	}
	shortestPath(K);
	for (int a = 1; a <= V; a++) {
		if (dist[a] == INF) cout << "INF" << '\n';
		else cout << dist[a] << '\n';
	}
}
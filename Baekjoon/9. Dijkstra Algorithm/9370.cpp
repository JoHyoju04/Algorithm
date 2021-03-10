/*
	< 9370 : 미확인 도착지 >
	방법 : s에서 목적지 후보까지 최단경로를 구한 것이 g,h를 지나는 최단거리이면 출력

	s에서 g를 지나는 h까지의 최단거리 : sgh변수,s에서 h를 지나는 g까지의 최단거리 : shg변수
*/
#include <iostream>
#include<vector>
#include<queue>
#include <algorithm>
#define MAX_VERTICES 2001
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[MAX_VERTICES];
vector<int> dist(MAX_VERTICES, INF);
vector<int> candidate;
void shortestPath(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	dist.assign(MAX_VERTICES, INF);
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int hear = pq.top().second;
		pq.pop();
		if (dist[hear] < cost) continue;
		for (int i = 0; i < graph[hear].size(); i++) {
			int next = graph[hear][i].first;
			int nextDist = cost + graph[hear][i].second;
			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push({ -nextDist,next });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		candidate.assign(n + 1, MAX_VERTICES);
		for (int i = 0; i <= n; i++) graph[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			graph[a].push_back({ b,d });
			graph[b].push_back({ a,d });
		}
		for (int i = 0; i < t; i++) {
			cin >> candidate[i];
		}
		sort(candidate.begin(), candidate.end());
		shortestPath(s);
		int sgh = dist[g];
		int shg = dist[h];
		shortestPath(g);
		sgh += dist[h];
		shg += dist[h];
		for (int i = 0; i < t; i++) {
			shortestPath(candidate[i]);
			if (dist[s] != INF && (dist[s] == sgh + dist[h] || dist[s] == shg + dist[g])) {
				cout << candidate[i] << " ";
			}
		}
		cout << "\n";
	}
}
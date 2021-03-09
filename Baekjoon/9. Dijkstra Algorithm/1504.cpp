/*
	< 1504 : 특정한 최단 경로 >

	정점1부터 정점N까지 정점V1,V2를 지나는 경우의 수
	1. 1->V1~~V2->N : 1(시작정점) 바로 다음에  V1을 지나고 V1과 V2의 최단경로를 지난후에 V2와 N까지의 거리
	2. 1->V2~~V1->N : 1(시작정점) 바로 다음에  V2을 지나고 V2과 V1의 최단경로를 지난후에 V1와 N까지의 거리

	1의 값과 2의 값을 구해서 작은 값이 최단경로가 된다.

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
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		graph[from].push_back({ to,val });
		graph[to].push_back({ from,val });
	}
	int V1, V2, result, sum[3] = { 0, };
	cin >> V1 >> V2;
	shortestPath(V1);
	// 정점V1 -> 정점V2의 최단거리
	result = dist[V2];	

	// 정점V1과 V1의 경로가 없으면
	if (dist[V2] == INF) {
		cout << "-1";
		return 0;
	}
	shortestPath(1);
	//sum[0]은 정점1 -> 정점V1의 최단거리, sum[1]은 정점1 -> 정점v2의 최단거리
	sum[0] = dist[V1]; sum[1] = dist[V2];

	shortestPath(V);
	//sum[0]은 (정점1 -> 정점V1의 최단거리)+(정점V ->정점V2의 최단거리) , sum[1]은 (정점1 -> 정점V2의 최단거리) + (정점V ->정점V1의 최단거리)
	sum[0] += dist[V2]; sum[1] += dist[V1];

	//최솟값 찾아주기
	int min = (sum[0] < sum[1]) ? sum[0] : sum[1];
	if (min == INF)cout << "-1";
	else cout << result + min;	// 최솟값에 정점V1와 정점V2의 최단거리 더해주기
}
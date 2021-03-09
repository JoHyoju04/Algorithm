/*
	< 1504 : Ư���� �ִ� ��� >

	����1���� ����N���� ����V1,V2�� ������ ����� ��
	1. 1->V1~~V2->N : 1(��������) �ٷ� ������  V1�� ������ V1�� V2�� �ִܰ�θ� �����Ŀ� V2�� N������ �Ÿ�
	2. 1->V2~~V1->N : 1(��������) �ٷ� ������  V2�� ������ V2�� V1�� �ִܰ�θ� �����Ŀ� V1�� N������ �Ÿ�

	1�� ���� 2�� ���� ���ؼ� ���� ���� �ִܰ�ΰ� �ȴ�.

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
	// ����V1 -> ����V2�� �ִܰŸ�
	result = dist[V2];	

	// ����V1�� V1�� ��ΰ� ������
	if (dist[V2] == INF) {
		cout << "-1";
		return 0;
	}
	shortestPath(1);
	//sum[0]�� ����1 -> ����V1�� �ִܰŸ�, sum[1]�� ����1 -> ����v2�� �ִܰŸ�
	sum[0] = dist[V1]; sum[1] = dist[V2];

	shortestPath(V);
	//sum[0]�� (����1 -> ����V1�� �ִܰŸ�)+(����V ->����V2�� �ִܰŸ�) , sum[1]�� (����1 -> ����V2�� �ִܰŸ�) + (����V ->����V1�� �ִܰŸ�)
	sum[0] += dist[V2]; sum[1] += dist[V1];

	//�ּڰ� ã���ֱ�
	int min = (sum[0] < sum[1]) ? sum[0] : sum[1];
	if (min == INF)cout << "-1";
	else cout << result + min;	// �ּڰ��� ����V1�� ����V2�� �ִܰŸ� �����ֱ�
}
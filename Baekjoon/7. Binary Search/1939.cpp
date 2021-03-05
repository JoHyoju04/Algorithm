/*
< 1939 : 중량제한 >
1.이분탐색
- low=1, high=입력받은 중량제한 중 가장 큰값, mid=(low+high)/2
- mid값으로 시작 섬(start_i)부터 마지막 섬(end_i)까지 탐색하면 답(answer)갱신,low=mid+1
- mid값으로 탐색 못하면 high=mid-1

2. BFS
- 시작 섬(start_i)부터 마지막 섬(end_i)까지 탐색
- 방문하지 않은 섬 + 현재 섬과 방문할 섬 사이의 중량제한이 mid보다 크거나 같으면 방문한다.
- 현재 섬이 마지막 섬이면 true, 탐색이 끝난 후 마지막 섬을 찾지 못하면 false

주의할 점 : vector<vector<int> > island인 인접행렬을 이용하면 N은 최대 10만이니 메모리초과이므로 인접리스트(vector<pair<int,int> > island)를 이용한다.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<bool> visited;
vector<pair<int, int> > island[10001];
int N, M, start_i, end_i;
bool BFS(int mid) {
	queue<int> que;
	que.push(start_i);
	visited[start_i] = true;
	while (!que.empty()) {
		int node = que.front();
		que.pop();
		if (node == end_i)	return true;
		int size = island[node].size();
		for (int i = 0; i < size; i++) {
			if (!visited[island[node][i].first] && island[node][i].second >= mid) {
				que.push(island[node][i].first);
				visited[island[node][i].first] = true;
			}
		}
	}
	return false;
}
int main()
{
	int max = 0, answer = 1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		island[A].push_back({ B,C });
		island[B].push_back({ A,C });
		max = max > C ? max : C;
	}
	cin >> start_i >> end_i;
	int low = 1, high = max;
	while (low <= high) {
		visited.assign(N + 1, 0);
		int mid = (low + high) / 2;
		if (BFS(mid)) {
			answer = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << answer;
	return 0;
}

/*
< 1939 : �߷����� >
1.�̺�Ž��
- low=1, high=�Է¹��� �߷����� �� ���� ū��, mid=(low+high)/2
- mid������ ���� ��(start_i)���� ������ ��(end_i)���� Ž���ϸ� ��(answer)����,low=mid+1
- mid������ Ž�� ���ϸ� high=mid-1

2. BFS
- ���� ��(start_i)���� ������ ��(end_i)���� Ž��
- �湮���� ���� �� + ���� ���� �湮�� �� ������ �߷������� mid���� ũ�ų� ������ �湮�Ѵ�.
- ���� ���� ������ ���̸� true, Ž���� ���� �� ������ ���� ã�� ���ϸ� false

������ �� : vector<vector<int> > island�� ��������� �̿��ϸ� N�� �ִ� 10���̴� �޸��ʰ��̹Ƿ� ��������Ʈ(vector<pair<int,int> > island)�� �̿��Ѵ�.
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

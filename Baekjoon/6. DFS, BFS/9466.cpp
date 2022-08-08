#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100001
using namespace std;

int t, n;
int graph[MAX];
bool visited[MAX];
bool done[MAX];
int cnt;
void hasCycle(int node) {

	visited[node] = true;
	int next = graph[node];


	if (!visited[next]) {
		hasCycle(next);
	}
	else if (!done[next]) {//�湮�� ������ ���� ����Ŭ�� �ƴ϶�� next���� �����ؼ� ����Ŭ �ϼ�
		//�ڱ� �ڽ��� ������ ���� ����� ī��Ʈ
		for (int i = next; i != node; i = graph[i]) {
			cnt++;
		}
		cnt++;
	}
	done[node] = true;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				hasCycle(i);
			}
		}
		cout << n - cnt << '\n';
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			graph[i] = 0;
			done[i] = 0;
			visited[i] = 0;
		}
	}


	return 0;
}
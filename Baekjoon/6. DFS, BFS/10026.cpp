#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[101][101];
char map[101][101];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int N;

void bfs(int sr, int sc, string str) {
	char ch = map[sr][sc];
	queue<pair<int, int> > q;
	q.push({ sr,sc });
	visited[sr][sc] = 1;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || visited[nr][nc])	continue;
			if (str == "not") {
				if ((ch == 'R' || ch == 'G') && (map[nr][nc] == 'R' || map[nr][nc] == 'G')) {
					q.push({ nr,nc });
					visited[nr][nc] = 1;
					continue;
				}
			}
			if (ch == map[nr][nc]) {
				q.push({ nr,nc });
				visited[nr][nc] = 1;
			}
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> answer;
	int cnt = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j, "normal");
				cnt++;
			}
		}
	}
	answer.push_back(cnt);
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j, "not");
				cnt++;
			}
		}
	}
	answer.push_back(cnt);
	cout << answer[0] << " " << answer[1];

	return 0;
}
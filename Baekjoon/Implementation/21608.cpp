#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int school[21][21];
int like[402][4];
int N;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int> > vec;
	vector<int> order;
	int answer = 0;
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		order.push_back(a);
		like[a][0] = b;
		like[a][1] = c;
		like[a][2] = d;
		like[a][3] = e;
	}

	for (int k = 0; k < N * N; k++) {
		int curN = order[k];
		int maxCnt = 0;
		vec.clear();
		//1번 수행
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (school[i][j] != 0)	continue;
				int cnt = 0;
				for (int a = 0; a < 4; a++) {
					int nr = i + dir[a][0];
					int nc = j + dir[a][1];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N)	continue;
					for (int b = 0; b < 4; b++) {
						if (school[nr][nc] == like[curN][b])	cnt++;
					}
				}
				vec.push_back({ cnt,i,j });
				maxCnt = maxCnt > cnt ? maxCnt : cnt;
			}
		}

		for (int i = 0; i < vec.size();) {
			if (vec[i][0] != maxCnt) {
				vec.erase(vec.begin() + i);
			}
			else ++i;
		}

		//1번의 경우가 하나일때
		if (vec.size() == 1) {
			school[vec[0][1]][vec[0][2]] = curN;
			continue;
		}
		maxCnt = 0;
		int sR = -1, sC = -1;
		for (int i = 0; i < vec.size(); i++) {
			int r = vec[i][1];
			int c = vec[i][2];
			int cnt = 0;
			for (int j = 0; j < 4; j++) {
				int nr = r + dir[j][0];
				int nc = c + dir[j][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)	continue;
				if (school[nr][nc] == 0)	cnt++;
			}
			if (sR == -1 || maxCnt < cnt) {
				sR = r;
				sC = c;
				maxCnt = cnt;
			}
			else if (maxCnt == cnt) {
				if (sR == -1 || sR > r) {
					sR = r;
					sC = c;
				}
				else if (sR == r && sC > c) {
					sR = r;
					sC = c;
				}
			}
		}
		school[sR][sC] = curN;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int curN = school[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nr = i + dir[k][0];
				int nc = j + dir[k][1];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)	continue;
				for (int b = 0; b < 4; b++) {
					if (school[nr][nc] == like[curN][b])	cnt++;
				}
			}
			answer += pow(10, cnt - 1);
		}
	}

	cout << answer;
	return 0;
}
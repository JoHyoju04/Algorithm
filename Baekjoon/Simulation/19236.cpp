#include <iostream>
#include <vector>
using namespace std;

struct Shark {
	int r, c, d;
};

int dir[8][2] = { {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
int map[4][4];
int fish[17];
int answer, sum;
Shark shark;

void move(int r, int c) {
	int n = map[r][c];
	int d = fish[n];
	int tr = r, tc = c;
	int cnt = 0;
	for (int i = d; cnt != 8; i = (i + 1) % 8) {
		cnt++;
		tr = r + dir[i][0];
		tc = c + dir[i][1];
		if (tr < 0 || tc < 0 || tr >= 4 || tc >= 4 || map[tr][tc] == 17)	continue;
		map[r][c] = map[tr][tc];
		map[tr][tc] = n;
		fish[n] = i;
		break;
	}
}

void dfs() {
	answer = answer > sum ? answer : sum;
	int tmp[4][4];
	int tmpFish[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	for (int i = 1; i < 17; i++)	tmpFish[i] = fish[i];

	//물고기 이동
	int num = 1;
	bool flag = false;
	while (num != 17) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (num == map[i][j]) {
					move(i, j);
					flag = true;
					break;
				}
			}
			if (flag)	break;
		}
		num++;
		flag = false;
	}

	//상어이동
	Shark t = shark;
	int tr = shark.r;
	int tc = shark.c;
	while (true) {
		tr += dir[t.d][0];
		tc += dir[t.d][1];
		if (tr < 0 || tc < 0 || tr >= 4 || tc >= 4) break;
		if (map[tr][tc] == 0)	continue;
		int n = map[tr][tc];
		map[t.r][t.c] = 0;
		map[tr][tc] = 17;
		sum += n;
		shark = { tr,tc,fish[n] };
		dfs();
		sum -= n;
		shark = t;
		map[t.r][t.c] = 17;
		map[tr][tc] = n;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			map[i][j] = tmp[i][j];
		}
	}
	for (int i = 1; i < 17; i++)	fish[i] = tmpFish[i];
	return;

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	answer = 0, sum = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			fish[a] = b - 1;
			map[i][j] = a;
		}
	}

	if (map[0][0] == 0) {
		cout << answer;
		return 0;
	}
	sum = map[0][0];
	shark = { 0,0,fish[map[0][0]] };
	map[0][0] = 17;

	dfs();

	cout << answer;
	return 0;
}
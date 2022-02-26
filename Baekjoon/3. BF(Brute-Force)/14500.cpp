#include<iostream>
using namespace std;

bool visited[501][501];
int map[501][501];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int dirUP[3][2] = { {0,1},{0,2},{-1,1} };
int dirDOWN[3][2] = { {0,1},{0,2},{1,1} };
int dirRight[3][2] = { {1,0},{1,1},{2,0} };
int dirLeft[3][2] = { {1,0},{1,-1},{2,0} };
int answer, sum, N, M;

void move(int r, int c, int d[3][2]) {
    sum = map[r][c];
    for (int i = 0; i < 3; i++) {
        int nr = r + d[i][0];
        int nc = c + d[i][1];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M) return;
        sum += map[nr][nc];
    }
    answer = answer > sum ? answer : sum;
}

void dfs(int r, int c, int depth) {
    if (depth == 3) {
        answer = answer > sum ? answer : sum;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc]) continue;
        sum += map[nr][nc];
        visited[nr][nc] = 1;
        dfs(nr, nc, depth + 1);
        sum -= map[nr][nc];
        visited[nr][nc] = 0;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            sum = map[i][j];
            visited[i][j] = 1;
            dfs(i, j, 0);
            visited[i][j] = 0;

            move(i, j, dirUP);
            move(i, j, dirDOWN);
            move(i, j, dirRight);
            move(i, j, dirLeft);

        }
    }
    cout << answer;

    return 0;
}
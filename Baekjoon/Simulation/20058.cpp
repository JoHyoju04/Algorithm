#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int map[65][65];
int tmp[65][65];
bool visited[65][65];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int N, Q;

void rotate(int y, int x, int L) {
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            tmp[i][j] = map[y + L - 1 - j][x + i];
    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            map[y + i][x + j] = tmp[i][j];
}

void melt() {
    vector<vector<bool> > check(N, vector<bool>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            if (map[i][j] == 0)    continue;
            for (int k = 0; k < 4; k++) {
                int nr = i + dir[k][0];
                int nc = j + dir[k][1];
                if (nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc] == 0)    continue;
                cnt++;
            }
            if (cnt < 3)  check[i][j] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (check[i][j]) map[i][j]--;
        }
    }
}
int bfs(int r, int c) {
    queue<pair<int, int> > q;
    int ret = 1;
    q.push({ r,c });
    visited[r][c] = 1;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc] <= 0 || visited[nr][nc])  continue;
            ret++;
            q.push({ nr,nc });
            visited[nr][nc] = 1;
        }
    }
    return ret;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    N = pow(2, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }


    for (int i = 0; i < Q; i++) {
        int input;
        cin >> input;
        input = pow(2, input);
        for (int j = 0; j < N; j += input) {
            for (int k = 0; k < N; k += input) {
                rotate(j, k, input);
            }
        }
        melt();
    }

    int sum = 0, cellCnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += map[i][j];
            if (map[i][j] > 0 && !visited[i][j]) {
                cellCnt = max(cellCnt, bfs(i, j));
            }
        }
    }
    cout << sum << "\n" << cellCnt;
    return 0;
}
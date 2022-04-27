#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct Group
{
    int num, size, rainbow, r, c;
};

int map[21][21];
bool visited[21][21];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int tmp[21][21];
int N, M;

void down() {
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= 0; j--) {
            if (map[j][i] < 0) continue;
            int n = map[j][i];
            int row = j;
            int idx = j + 1;

            while (idx < N && map[idx][i] < -1) {
                idx++;
            }
            map[row][i] = -100;
            map[idx - 1][i] = n;

        }
    }
}
void bfs(int r, int c, int n, Group& g) {
    int num = tmp[r][c];
    int rainbowCnt = 0;
    int gr = r, gc = c;
    tmp[r][c] = n;
    if (g.num == n)    tmp[r][c] = -100;
    visited[r][c] = 1;

    queue<pair<int, int> > q;
    q.push({ r,c });

    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])   continue;
            if (tmp[nr][nc] == num || tmp[nr][nc] == 0) {
                visited[nr][nc] = 1;
                q.push({ nr,nc });
                if (g.num == n) tmp[nr][nc] = -100;
                else if (tmp[nr][nc] != 0) {
                    if (nr < gr || (nr == gr && nc < gc)) {
                        gr = nr;
                        gc = nc;
                    }
                    tmp[nr][nc] = n;
                }
                else rainbowCnt++;


            }
        }
    }
    if (g.num == n) return;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tmp[i][j] == n)    cnt++;
            if (tmp[i][j] == 0)    visited[i][j] = 0;
        }
    }
    cnt += rainbowCnt;
    if (cnt >= 2) {
        Group gg = { n,cnt,rainbowCnt,gr,gc };
        if (cnt > g.size) {
            g = gg;
        }
        else if (cnt == g.size) {
            if (rainbowCnt > g.rainbow) {
                g = gg;
            }
            else if (rainbowCnt == g.rainbow) {
                if (gr > g.r) {
                    g = gg;
                }
                else if (gr == g.r && gc > g.c) {
                    g = gg;
                }
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tmp[i][j] == n) {
                    tmp[i][j] = map[i][j];
                }
            }
        }
    }

    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int a = 0;
    while (true) {
        //그룹 초기화
        Group g = { 0,0,0,0,0 };

        //tmp를 map으로 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = map[i][j];
                visited[i][j] = 0;
            }
        }

        //그룹번호를 6부터 시작하고 tmp로 bfs 탐색
        int cnt = 6;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && tmp[i][j] > 0) {
                    bfs(i, j, cnt, g);
                    cnt++;
                }
            }
        }

        if (g.num == 0)    break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tmp[i][j] == g.num) {
                    bfs(i, j, g.num, g);
                }
            }
        }

        //점수 계산
        answer += (g.size * g.size);

        //map으로 옮겨주기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tmp[i][j] == -100)
                    map[i][j] = tmp[i][j];
            }
        }

        //중력
        down();

        //rotate
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j < N; j++) {
                tmp[N - 1 - i][j] = map[j][i];
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = tmp[i][j];
            }
        }


        down();

    }
    cout << answer;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int map[101][101];
bool visited[101][101];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, remain = 0, cnt = 0, time = 0;
    queue<pair<int, int> > q;
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            cnt += map[i][j];
            if (i == 0 || i == R - 1 || j == 0 || j == C - 1)    q.push({ i,j });
        }
    }
    while (true) {
        time++;
        vector<pair<int, int> > vec;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr < 0 || nc < 0 || nr >= R || nc >= C || visited[nr][nc])    continue;
                if (map[nr][nc] == 0) {
                    q.push({ nr,nc });
                }
                else {
                    vec.push_back({ nr,nc });
                    map[nr][nc] = 0;
                }
                visited[nr][nc] = 1;
            }
        }

        for (int i = 0; i < vec.size(); i++) {
            q.push({ vec[i].first,vec[i].second });
        }
        remain = cnt;
        cnt -= vec.size();
        if (cnt == 0)  break;
        vec.clear();
    }
    cout << time << "\n" << remain;
    return 0;
}
/*
#include <iostream>
#include <queue>
#include <vector>
#define MAX 101
#define INF 987654321
using namespace std;

int n, m, ans, cnt;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue<pair<int,int> > q, nq;

void bfs() {
    q.push({ 0,0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;

            if (map[nx][ny] == 0) {
                q.push({ nx,ny });
                visited[nx][ny] = true;
            }
            else if (map[nx][ny] == 1) {
                nq.push({ nx,ny });
                visited[nx][ny] = true;
            }
        }

        if (q.empty()) {
            while (!nq.empty()) {
                int mx = nq.front().first;
                int my = nq.front().second;
                nq.pop();

                map[mx][my] = 0;
                q.push({ mx,my });
            }

            if (!q.empty()) {
                ans++;
                cnt = (int)q.size();
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            visited[i][j] = false;
        }
    }

    ans = 0;
    cnt = 0;
    bfs();
    cout << ans << "\n" << cnt << "\n";

    return 0;
}
*/
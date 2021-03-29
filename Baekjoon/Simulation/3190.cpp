#include <iostream>
#include<vector>
#include <queue>
using namespace std;
struct loc {
    int r, c, time, d;
};
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<int> > map;
vector<vector<bool> > visited;
vector <pair<int, char> > m;
int N, K, L;
int head(int d, int cur, int curD, char c, int& D) {
    if (c == 'L') {
        switch (curD) {
        case 0: D = 2; break;
        case 1: D = 3; break;
        case 2: D = 1; break;
        case 3: D = 0; break;
        }
    }
    else {
        switch (curD)
        {
        case 0: D = 3; break;
        case 1: D = 2; break;
        case 2: D = 0; break;
        case 3: D = 1; break;
        }
    }
    return cur + dir[D][d];
}
int bfs() {
    queue <loc> q;
    queue<pair<int, int> > snake;
    q.push({ 0,0,0,2 });
    snake.push({ 0,0 });
    visited[0][0] = 1;
    int order = 0, D = 2;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int moveR, moveC;
        if (order < L && m[order].first == cur.time) {
            moveR = head(0, cur.r, cur.d, m[order].second, D);
            moveC = head(1, cur.c, cur.d, m[order].second, D);
            order++;
        }
        else {
            moveR = cur.r + dir[D][0];
            moveC = cur.c + dir[D][1];
        }
        if (moveR < 0 || moveR >= N || moveC < 0 || moveC >= N || visited[moveR][moveC])
            return cur.time + 1;
        else {
            q.push({ moveR,moveC,cur.time + 1,D });
            visited[moveR][moveC] = 1;
            snake.push({ moveR,moveC });

            if (map[moveR][moveC] == 1) {
                map[moveR][moveC] = 0;
            }
            else {
                visited[snake.front().first][snake.front().second] = 0;
                snake.pop();
            }
        }

    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    map.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, 0));
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int x; char c;
        cin >> x >> c;
        m.push_back({ x, c });
    }
    int answer = bfs();
    cout << answer;
    return 0;
}
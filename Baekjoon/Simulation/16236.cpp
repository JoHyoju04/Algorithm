#include <iostream>
#include<vector>
#include<queue>
using namespace std;
struct Shark {
    int x, y, stime;
};
struct compare {
    bool operator()(Shark t, Shark u) {
        if (t.stime == u.stime) {
            if (t.x == u.x)
                return t.y > u.y;
            else
                return t.x > u.x;

        }
        else return t.stime > u.stime;
    }
};
int N;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<bool> > visited;
vector<vector<int> > map;
queue<Shark> q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    map.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                map[i][j] = 0;
                q.push({ i,j,0 });
                visited[i][j] = true;
            }
        }
    }
    int vol = 2, eat = 0, time = 0;
    while (1) {
        priority_queue<Shark, vector<Shark>, compare> pq;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int moveX = cur.x + dir[i][0];
                int moveY = cur.y + dir[i][1];
                if (moveX < 0 || moveX >= N || moveY < 0 || moveY >= N)    continue;
                if (map[moveX][moveY] <= vol && !visited[moveX][moveY]) {
                    q.push({ moveX,moveY,cur.stime + 1 });
                    visited[moveX][moveY] = true;
                    if (map[moveX][moveY] < vol && map[moveX][moveY] != 0) pq.push({ moveX,moveY,cur.stime + 1 });
                }
            }
        }
        visited.assign(N, vector<bool>(N, 0));
        if (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            map[cur.x][cur.y] = 0;
            eat++;
            time = cur.stime;
            q.push({ cur.x,cur.y,time });
            visited[cur.x][cur.y] = true;
        }
        else {
            cout << time;
            break;
        }
        if (eat == vol) {
            vol++;
            eat = 0;
        }
    }
    return 0;
}
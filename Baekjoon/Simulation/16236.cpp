#include<iostream>
#include<queue>
using namespace std;

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int map[21][21];
bool visited[21][21];
int N;

struct shark {
    int r, c, moveCnt;
};

struct cmp {
    bool operator()(shark a, shark b) {
        if (a.moveCnt == b.moveCnt) {
            if (a.r == b.r)    return a.c > b.c;
            else return a.r > b.r;
        }
        return a.moveCnt > b.moveCnt;
    }
};
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            visited[i][j] = 0;
    }
}

int bfs(int r, int c) {
    int size = 2, fishCnt = 0, time = 0;
    map[r][c] = 0;
    while (true) {
        priority_queue<shark, vector<shark>, cmp> pq;
        queue<shark> q;
        q.push({ r,c,0 });
        visited[r][c] = 1;
        while (!q.empty()) {
            int curR = q.front().r;
            int curC = q.front().c;
            int curCnt = q.front().moveCnt;
            q.pop();
            if (map[curR][curC] != 0 && map[curR][curC] < size) {
                pq.push({ curR,curC,curCnt });
            }
            for (int i = 0; i < 4; i++) {
                int nR = curR + dir[i][0];
                int nC = curC + dir[i][1];
                if (nR < 0 || nR >= N || nC<0 || nC >= N || visited[nR][nC] || map[nR][nC]>size)    continue;
                visited[nR][nC] = 1;
                q.push({ nR,nC,curCnt + 1 });
            }
        }

        if (pq.size() == 0)    return time;
        bool check = false;
        while (!pq.empty()) {
            if (check)   pq.pop();
            else {
                r = pq.top().r;
                c = pq.top().c;
                time += pq.top().moveCnt;
                pq.pop();
                map[r][c] = 0;
                fishCnt++;
                check = true;
            }
        }

        if (fishCnt == size) {
            size++;
            fishCnt = 0;
        }

        init();
    }
}

int main() {
    int startR = 0, startC = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                startR = i;
                startC = j;
            }
        }
    }
    cout << bfs(startR, startC);

    return 0;
}

/*
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
*/
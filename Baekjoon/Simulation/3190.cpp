#include<iostream>
#include<queue>
using namespace std;

int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
bool apple[101][101];
char change[10001];
bool visited[101][101];
int N, K, L;

int dummy() {
    int curR = 0, curC = 0;
    int time = 0, dIdx = 0;;
    queue<pair<int, int> > q;
    q.push({ 0,0 });
    while (true) {
        time++;
        curR += dir[dIdx][0];
        curC += dir[dIdx][1];

        //�� �Ǵ� �ڱ� �ڽ��� ���� �ε����� ���� ����
        if (curR < 0 || curC < 0 || curR >= N || curC >= N || visited[curR][curC])    return time;

        visited[curR][curC] = 1;

        //�Ӹ�
        q.push({ curR,curC });

        //����
        int tailR = q.front().first;
        int tailC = q.front().second;

        //����� ������ ������ġ�� �湮ǥ�� ���ְ� queue�� ������ġ pop
        if (!apple[curR][curC]) {
            visited[tailR][tailC] = 0;
            q.pop();

        }
        else apple[curR][curC] = 0; //��������� ������ش�

        //������ȯ������ ���� �״��
        if (change[time] != 'L' && change[time] != 'D')   continue;

        //������ȯ������ ���� �ٲ۴�
        if (change[time] == 'L') dIdx = (dIdx + 1) % 4;
        else if (dIdx - 1 < 0) dIdx = 3;
        else dIdx -= 1;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        apple[r - 1][c - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int t;
        char x;
        cin >> t >> x;
        change[t] = x;
    }
    cout << dummy();
    return 0;
}

/*
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
*/
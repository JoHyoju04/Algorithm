#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int R, C;
char map[51][51];
queue<pair<int, int> > wq;
queue<pair<int, int> > aq;
int cnt[51][51];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool isRange(int r, int c) {
    if (r < 0 || c < 0 || r >= R || c >= C)    return false;
    return true;
}

int bfs() {
    int ret = -1;
    while (!wq.empty() || !aq.empty()) {
        int r, c, nr, nc, i, j;
        int size = wq.size();
        for (i = 0; i < size; i++) {
            r = wq.front().first;
            c = wq.front().second;
            wq.pop();
            for (j = 0; j < 4; j++) {
                nr = r + dir[j][0];
                nc = c + dir[j][1];
                if (!isRange(nr, nc) || map[nr][nc] == 'X' || map[nr][nc] == 'D' || map[nr][nc] == '*') continue;
                wq.push({ nr,nc });
                map[nr][nc] = '*';
            }
        }
        size = aq.size();
        for (i = 0; i < size; i++) {
            r = aq.front().first;
            c = aq.front().second;
            aq.pop();
            if (map[r][c] == 'D') {
                ret = cnt[r][c];
                break;
            }
            for (j = 0; j < 4; j++) {
                nr = r + dir[j][0];
                nc = c + dir[j][1];
                if (!isRange(nr, nc) || map[nr][nc] == 'X' || cnt[nr][nc] > 0 || map[nr][nc] == '*') continue;
                aq.push({ nr,nc });
                cnt[nr][nc] = cnt[r][c] + 1;
            }
        }
        if (ret != -1) break;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == '*')  wq.push({ i,j });
            if (map[i][j] == 'S') aq.push({ i,j });
        }
    }
    int answer = bfs();
    if (answer == -1)  cout << "KAKTUS";
    else cout << answer;
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > map(101, vector<int>(101, 0));
int dir[4][3] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;
void BFS() {
    queue<pair<int, int> > que;
    pair<int, int> curr;
    int r, c;
    que.push({ 0,0 });
    while (!que.empty()) {
        curr = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            r = curr.first + dir[i][0];
            c = curr.second + dir[i][1];
            if (r >= 0 && r < N && c >= 0 && c < M && map[r][c] == 1) {
                que.push({ r,c });
                map[r][c] = map[curr.first][curr.second] + 1;
            }
        }
    }
    return;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    BFS();
    cout << map[N - 1][M - 1];

    return 0;
}
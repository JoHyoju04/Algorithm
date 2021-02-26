#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int map[1001][1001];
int cnt[1001][1001][2];
int dir[4][3] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;
int bfs() {
    queue<pair<pair<int, int>, int > > q;
    q.push({ {0,0} , 1 }); // y, x, block 뚫을수 있는 횟수
    cnt[0][0][1] = 1;

    while (!q.empty()) {
        int R = q.front().first.first;
        int C = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if (R == N - 1 && C == M - 1) {
            return cnt[R][C][block];
        }

        for (int i = 0; i < 4; i++) {
            int r = R + dir[i][0];
            int c = C + dir[i][1];

            // 맵을 벗어나지 않고,
            if (r >= 0 && r < N && c >= 0 && c < M) {
                // 갈 수없는 길(벽)이고, 벽을 아직 안뚫었을때
                if (map[r][c] == 1 && block) {
                    cnt[r][c][block - 1] = cnt[R][C][block] + 1;
                    q.push({ { r,c }, block - 1 });
                }
                // 갈 수있는 길이고, 방문하지 않았다면
                if (map[r][c] == 0 && cnt[r][c][block] == 0) {
                    cnt[r][c][block] = cnt[R][C][block] + 1;
                    q.push({ { r,c }, block });
                }
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    cout << bfs();

    return 0;
}
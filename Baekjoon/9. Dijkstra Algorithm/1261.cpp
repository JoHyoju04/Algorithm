#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<vector<int> > graph(101, vector<int>(101, 0));
vector<vector<bool> > visited(101, vector<bool>(101, 0));
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M;
int dijkstra() {
    priority_queue< pair<pair<int, int>, int> > pq;
    visited[0][0] = 1;
    pq.push({ {0,0},0 });

    while (!pq.empty()) {
        int curCnt = -pq.top().first.first;
        int curRow = -pq.top().first.second;
        int curCol = pq.top().second;
        pq.pop();

        if (curRow == N - 1 && curCol == M - 1)    return curCnt;

        for (int i = 0; i < 4; i++) {
            int r = dir[i][0] + curRow;
            int c = dir[i][1] + curCol;
            if (r >= 0 && c >= 0 && r < N && c < M && !visited[r][c]) {
                if (graph[r][c] == 0) {
                    pq.push({ { -curCnt,-r }, c });
                    visited[r][c] = 1;
                }
                else {
                    pq.push({ {-(curCnt + 1),-r},c });
                    visited[r][c] = 1;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    cout << dijkstra();
    return 0;
}
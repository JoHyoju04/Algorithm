#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > map;
vector<vector<bool> > visited;
int mv[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int T, M, N, K, answer = 0;
void DFS(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int y_loc = y + mv[i][0];
        int x_loc = x + mv[i][1];
        if (y_loc >= 0 && y_loc < N && x_loc >= 0 && x_loc < M) {
            if (map[y_loc][x_loc] && !visited[y_loc][x_loc]) {
                visited[y_loc][x_loc] = true;
                DFS(y_loc, x_loc);
            }
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        answer = 0;
        map.assign(N + 1, vector<int>(M + 1, 0));
        visited.assign(N + 1, vector<bool>(M + 1, 0));
        for (int i = 0; i < K; i++) {
            int x_map, y_map;
            cin >> x_map >> y_map;
            map[y_map][x_map] = 1;
        }
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < M; b++) {
                if (map[a][b] && !visited[a][b]) {
                    DFS(a, b);
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
    return 0;
}
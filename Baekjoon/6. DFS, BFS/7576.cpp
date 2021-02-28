#include <iostream>
#include <queue>
using namespace std;
int tomato[1001][1001];
queue<pair<int, int> > que;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
int m, n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    int date = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) que.push({ i,j });
        }
    }
    while (!que.empty()) {
        int r_loc = que.front().first;
        int c_loc = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int r = r_loc + dir[i][0];
            int c = c_loc + dir[i][1];
            if (r >= 0 && r < n && c >= 0 && c < m && tomato[r][c] == 0) {
                que.push({ r,c });
                tomato[r][c] = tomato[r_loc][c_loc] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tomato[i][j] == 0) {
                cout << "-1";
                return 0;
            }
            date = date > tomato[i][j] ? date : tomato[i][j];
        }
    }
    cout << date - 1;
    return 0;
}
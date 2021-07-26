#include <vector>
#include<iostream>
#include<queue>
using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
vector<vector<int> >map;
vector<vector<int> > cnt;
int n, m;

void bfs(int startR, int startC) {
    queue<pair<int, int> > q;
    q.push({ startR,startC });
    cnt[startR][startC] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mR = r + dir[i][0];
            int mC = c + dir[i][1];
            if (mR < 0 || mR >= n || mC < 0 || mC >= m)    continue;
            if (cnt[mR][mC] == -1 && map[mR][mC] == 1) {
                cnt[mR][mC] = cnt[r][c] + 1;
                q.push({ mR,mC });
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    cin >> n >> m;
    map.assign(n, vector<int>(m,0));
    cnt.assign(n, vector<int>(m, -1));
    pair<int, int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2)  start=make_pair(i,j);
        }
    }

    bfs(start.first, start.second);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0)    cout << "0 ";
            else
            {
                cout << cnt[i][j]<<" ";
            }
        }
        cout << "\n";
    }
    return 0;
}

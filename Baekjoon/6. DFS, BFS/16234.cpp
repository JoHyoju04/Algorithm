#include <iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include <math.h>
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, L, R, cnt, answer = 0;
int map[51][51] = { 0, };
vector<vector<int> > visited;
bool BFS(int r, int c) {
    queue<pair<int, int> >q;
    q.push({ r,c });
    visited[r][c] = cnt;
    int population = map[r][c], nation = 1;

    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int adjR = curR + dir[i][0];
            int adjC = curC + dir[i][1];
            if (adjR >= 0 && adjR < N && adjC >= 0 && adjC < N && visited[adjR][adjC] == 0) {
                int gap = abs(map[curR][curC] - map[adjR][adjC]);
                if (L <= gap && R >= gap) {
                    q.push({ adjR,adjC });
                    visited[adjR][adjC] = cnt;
                    nation++;
                    population += map[adjR][adjC];
                }
            }
        }
    }
    if (nation == 1)   return false;
    else {
        int renew = trunc(population / nation);
        //cout << nation<<" " <<population<< " "<<renew << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == cnt)
                    map[i][j] = renew;
            }
        }
        return true;
    }
}
int main() {
    bool check = true;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    while (check) {
        visited.assign(N, vector<int>(N, 0));
        cnt = 1;
        check = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j] == 0 && BFS(i, j)) {
                    check = true;
                }
                cnt++;
            }
        }
        if (check)   answer++;
    }
    cout << answer;
    return 0;
}
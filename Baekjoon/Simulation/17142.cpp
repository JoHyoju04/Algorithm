#include <iostream>
#include<vector>
#include<queue>
#include<cstdlib>
#include <math.h>
#define MAX 987654321
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, M, answer = MAX;
int map[51][51] = { 0, };
vector<pair<int, int> > candidate;
vector<vector<int> > visited;
vector<pair<int, int> > virus;

int BFS() {
    queue<pair<int, int> >q;
    for (int i = 0; i < M; i++) {
        q.push({ candidate[i].first,candidate[i].second });
        visited[candidate[i].first][candidate[i].second] = 0;
    }
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int moveR = curR + dir[i][0];
            int moveC = curC + dir[i][1];
            if (moveR >= 0 && moveR < N && moveC >= 0 && moveC < N && visited[moveR][moveC] == -1 && map[moveR][moveC] != 1) {
                visited[moveR][moveC] = visited[curR][curC] + 1;
                q.push({ moveR,moveC });

            }
        }
    }
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == -1 && map[i][j] == 0) return MAX;
            else if (map[i][j] != 2)  max = max > visited[i][j] ? max : visited[i][j];
        }
    }
    return max;
}
void DFS(int cnt, int idx) {
    if (cnt == M) {
        visited.assign(N, vector<int>(N, -1));
        int time = BFS();
        answer = answer < time ? answer : time;
        return;
    }
    else {
        for (int i = idx; i < virus.size(); i++) {
            candidate.push_back({ virus[i].first,virus[i].second });
            DFS(cnt + 1, i + 1);
            candidate.pop_back();
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2)    virus.push_back({ i,j });
        }
    }
    DFS(0, 0);
    if (answer == MAX)  cout << "-1";
    else cout << answer;
    return 0;
}
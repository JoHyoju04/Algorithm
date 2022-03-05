#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define INF 987654321

struct car {
    int r, c, beforeDir, cost;
};
struct cmp {
    bool operator()(car a, car b) {
        return a.cost > b.cost;
    }
};
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int bfs(vector<vector<int> > board) {
    int N = board.size(), answer = INF;

    int cost[25][25][4];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < 4; ++k)
                cost[i][j][k] = INF;

    priority_queue<car, vector<car>, cmp> q;
    q.push({ 0,0,-1,0 });
    while (!q.empty()) {
        int curR = q.top().r;
        int curC = q.top().c;
        int before = q.top().beforeDir;
        int curCost = q.top().cost;
        q.pop();
        if (curR == N - 1 && curC == N - 1) {
            answer = answer < curCost ? answer : curCost;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nr = curR + dir[i][0];
            int nc = curC + dir[i][1];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N || board[nr][nc] == 1)    continue;
            int nCost;
            if (before == -1) nCost = 100;
            else if (before == i)  nCost = curCost + 100;
            else if ((before + 2) % 4 != i)    nCost = curCost + 600;

            if (cost[nr][nc][i] > nCost) {
                cost[nr][nc][i] = nCost;
                q.push({ nr,nc,i,nCost });
            }
        }
    }
    return answer;
}
int solution(vector<vector<int>> board) {
    int answer = bfs(board);
    return answer;
}
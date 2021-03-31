#include <iostream>
#include<vector>
#include <queue>
#include<string>
#include<algorithm>
using namespace std;

struct info {
    int start, end, cost;
};

vector<int> parent(7, 0);
vector<info> vec;
vector <vector<int> > map;
vector<vector<bool> > visited;
int N, M, answer = 0, iNum = 1;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void DFS(vector<vector<int> >& map, int r, int c, int num) {
    visited[r][c] = true;
    map[r][c] = num;
    for (int i = 0; i < 4; i++) {
        int mR = r + dir[i][0];
        int mC = c + dir[i][1];
        if (mR >= 0 && mR < N && mC >= 0 && mC < M && !visited[mR][mC] && map[mR][mC] == 1)
            DFS(map, mR, mC, num);
    }
}
int move(int& r, int& c, int d) {
    int ret = 0;
    r = r + dir[d][0], c = c + dir[d][1];
    while (1) {
        if (r >= 0 && r < N && c >= 0 && c < M && map[r][c] == 0) {
            ret++;
            r += dir[d][0];
            c += dir[d][1];
        }
        else if (r < 0 || r >= N || c < 0 || c >= M) return -1;
        else break;
    }
    if (ret <= 1)  return -1;
    else return ret;
}
void BFS(int r, int c) {
    queue <pair<int, int> > q;
    for (int i = r; i < N; i++) {
        for (int j = c; j < M; j++) {
            if (map[i][j] == map[r][c]) {
                q.push({ i,j });
            }
        }
    }
    while (!q.empty()) {
        int curR = q.front().first;
        int curC = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int mR = curR, mC = curC;
            int cnt = move(mR, mC, i);
            if (cnt == -1) continue;
            vec.push_back({ map[curR][curC],map[mR][mC],cnt });


        }
    }
}
int getParent(vector<int>& parent, int a) {
    if (parent[a] == a) return a;
    return parent[a] = getParent(parent, parent[a]);
}
void unionParent(vector<int>& parent, int a, int b) {
    int x = getParent(parent, a);

    int y = getParent(parent, b);
    if (x == y)    return;
    if (x < y) parent[y] = x;
    else parent[x] = y;
}
bool find(vector<int>& parent, int a, int b) {
    int x = getParent(parent, a);
    int y = getParent(parent, b);
    if (x == y)    return true;
    else return false;
}
bool compare(info a, info b) {
    return a.cost < b.cost;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    map.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                parent[iNum] = iNum;
                DFS(map, i, j, iNum);
                iNum++;
            }
        }
    }
    iNum -= 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] != 0) {
                visited.assign(N, vector<bool>(M, 0));
                BFS(i, j);
            }
        }
    }
    sort(vec.begin(), vec.end(), compare);
    bool visit[7][7] = { 0, };

    for (int i = 0; i < vec.size(); i++) {
        int s = vec[i].start;
        int e = vec[i].end;
        if (!visit[s][e] && !find(parent, s, e)) {
            iNum--;
            visit[s][e] = 1;
            visit[e][s] = 1;
            answer += vec[i].cost;
            unionParent(parent, s, e);
        }
    }

    if (iNum == 1)    cout << answer;
    else cout << "-1";


    return 0;
}
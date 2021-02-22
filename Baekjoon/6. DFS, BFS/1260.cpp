#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, V;
vector<vector<int> > map(1001, vector<int>(1001, 0));
vector<bool> visited(1001);
void DFS(int start) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && map[start][i]) {
            DFS(i);
        }
    }
}
void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int ver = q.front();
        q.pop();
        cout << ver << " ";
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && map[ver][i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main() {
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        map[v1][v2] = 1;
        map[v2][v1] = 1;
    }
    DFS(V);
    cout << "\n";
    visited.clear();
    visited.assign(N + 1, 0);
    BFS(V);

    return 0;
}
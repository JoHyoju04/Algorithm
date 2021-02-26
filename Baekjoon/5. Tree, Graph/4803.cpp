#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> >map;
vector<bool> visited;
int N, M;
bool isCycle(vector<int> t) {
    int cnt = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 1; j <= t[i]; j++) {
            if (map[t[i]][j] == 1) cnt++;
        }
    }
    if (cnt == t.size() - 1) return false;
    else return true;
}
int bfs(int start) {
    queue<int> que;
    que.push(start);
    visited[start] = true;
    vector<int> tree;
    while (!que.empty()) {
        int ver = que.front();
        que.pop();
        tree.push_back(ver);
        for (int i = 1; i <= N; i++) {
            if (map[ver][i] == 1 && !visited[i]) {
                que.push(i);
                visited[i] = true;
            }
        }
    }
    if (!isCycle(tree))   return 1;
    else return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 0;
    while (true) {
        cin >> N >> M;
        int v1, v2;
        int answer = 0;
        map.assign(N + 1, vector<int>(N + 1, 0));
        visited.assign(N + 1, false);
        if (N == 0) break;
        for (int i = 0; i < M; i++) {
            cin >> v1 >> v2;
            map[v1][v2] = 1;
            map[v2][v1] = 1;
        }
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) answer += bfs(i);
        }
        cout << "Case " << ++num << ": ";
        if (answer == 0)   cout << "No trees.\n";
        else if (answer == 1)  cout << "There is one tree.\n";
        else cout << "A forest of " << answer << " trees.\n";
    }

    return 0;
}
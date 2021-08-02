#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int n,m,maxCnt;
vector<int> answer;
vector<int> graph[10001];
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int cnt = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++) {
            if (!visited[graph[node][i]]) {
                cnt++;
                q.push(graph[node][i]);
                visited[graph[node][i]] = 1;
            }
        }
            
    }

    if (maxCnt <cnt ) {
        maxCnt = cnt;
        answer.clear();
        answer.push_back(start);
    }
    else if (maxCnt == cnt) {
        answer.push_back(start);
    }
    return;
}
int main() {
    cin.tie(NULL);   cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }
    maxCnt = 0;
    for (int i = 1; i <= n; i++) {
        visited.assign(n + 1, 0);
        bfs(i);
    }

    for (int i = 0; i < answer.size(); i++)    cout << answer[i] << " ";
   
    return 0;
}
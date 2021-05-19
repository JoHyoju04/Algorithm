#include <vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include <cstdlib>
using namespace std;

vector <int> graph[101];
vector<bool> visited;
vector<int> cnt;
int a, b, n, m;
void DFS(int start) {
    visited[start] = 1;
    for (int i = 0; i < graph[start].size(); i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            cnt[next] += cnt[start] + 1;
            if (next == b) return;
            else DFS(next);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cnt.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    DFS(a);
    if (cnt[b] == 0)   cout << -1;
    else cout << cnt[b];

    return 0;
}
#include <vector>
#include<iostream>
using namespace std;

vector<int> graph[2000];
vector<bool> visited;
int answer;

void DFS(int node,int d) {
    if (d == 4) {
        answer=1;
        return;
    }
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            DFS(next, d+1);
        }
    }
    visited[node] = false;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    answer = 0;
    for (int i = 0; i < N; i++) {
        visited.assign(N, 0);
        DFS(i, 0);
        if (answer == 1)   break;
    }
    cout << answer;

    return 0;
}

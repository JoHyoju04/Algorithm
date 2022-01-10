#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[501];
int answer[501];
int input_degree[501];
int cost[501];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    queue <int> q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int adjust;
        cin >> cost[i];
        while (true) {
            cin >> adjust;
            if (adjust == -1)  break;
            graph[adjust].push_back(i);
            input_degree[i]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (input_degree[i] == 0) {
            q.push(i);
            answer[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int j = 0; j < graph[cur].size(); j++) {
            int next = graph[cur][j];
            input_degree[next]--;
            answer[next] = answer[next] > cost[next] + answer[cur] ? answer[next] : cost[next] + answer[cur];
            if (input_degree[next] == 0)   q.push(next);
        }
    }

    for (int i = 1; i <= n; i++)   cout << answer[i] << "\n";
    return 0;
}
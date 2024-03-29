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
/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int input;
int cost[501];
vector<int> v[501];
int indegree[501];
int dp[501];

int main(int argc, char** argv) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    queue<int> q;
    memset(cost, 0, sizeof(cost));
    memset(indegree, 0, sizeof(indegree));
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= N; i++) {
        v[i].clear();
    }

    for (int i = 1; i <= N; i++) {
        cin >> input;
        cost[i] = input;
        while (true) {
            cin >> input;
            if (input == -1) break;
            v[input].push_back(i);
            indegree[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i] = cost[i];
        }
    }

    int vi;
    while (true) {
        if (q.empty()) break;
        int n = q.front();
        q.pop();
        for (int i = 0; i < v[n].size(); i++) {
            vi = v[n].at(i);
            dp[vi] = max(dp[n] + cost[vi], dp[vi]);
            indegree[vi]--;
            if (indegree[vi] == 0) {
                q.push(vi);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << dp[i] << endl;
    }

    return 0;
}
*/
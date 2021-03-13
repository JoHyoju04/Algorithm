#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
vector<pair<int, int> > graph[1002];
vector<int> dist;
vector<int> answer;
int N, M, X;
void dijkstra(int start) {
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < curDist) continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextDist = graph[cur][i].second + curDist;
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({ -nextDist,next });
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> X;
    answer.assign(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({ e,c });
    }
    for (int i = 1; i <= N; i++) {
        dist.assign(N + 1, INF);
        dijkstra(i);
        if (i == X) {
            for (int j = 1; j <= N; j++) {
                answer[j] += dist[j];
            }
        }
        else
        {
            answer[i] += dist[X];
        }
    }
    answer[X] = -1;
    int result = *max_element(answer.begin(), answer.end());
    cout << result;
    return 0;
}
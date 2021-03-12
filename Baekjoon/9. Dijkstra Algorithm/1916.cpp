/*
    < 1916 : 최소비용 구하기 >
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
vector<pair<int, int> > graph[1002];
vector<int> dist;
int N, M, sCity, eCity;
int dijkstra(int start, int end) {
    priority_queue<pair<int, int> > pq;
    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {
        int curDist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < curDist) continue;

        if (cur == end) return curDist;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nextDist = graph[cur][i].second + curDist;
            if (nextDist < dist[next]) {
                dist[next] = nextDist;
                pq.push({ -nextDist,next });
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    dist.assign(N + 1, INF);
    for (int i = 0; i < M; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({ e,c });
    }
    cin >> sCity >> eCity;
    cout << dijkstra(sCity, eCity);
    return 0;
}
#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int, int> > gragh[20001];
vector<int> dist;
void kruskal(int n, int start) {
    priority_queue < pair<int, int> > pq;
    pq.push({ 0,start });
    dist[start] = 0;
    while (!pq.empty()) {
        int curD = -pq.top().first;
        int curN = pq.top().second;
        pq.pop();
        if (dist[curN] < curD) continue;
        for (int i = 0; i < gragh[curN].size(); i++) {
            int nextD = curD + gragh[curN][i].second;
            int nextN = gragh[curN][i].first;
            if (nextD < dist[nextN]) {
                dist[nextN] = nextD;
                pq.push({ -nextD,nextN });
            }
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    dist.assign(n + 1, INF);
    for (int i = 0; i < edge.size(); i++) {
        gragh[edge[i][0]].push_back({ edge[i][1],1 });
        gragh[edge[i][1]].push_back({ edge[i][0],1 });
    }
    kruskal(n, 1);
    int max = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] != INF) {
            if (dist[i] > max) {
                max = dist[i];
                answer = 1;
            }
            else if (dist[i] == max)   answer++;
        }
    }
    return answer;
}
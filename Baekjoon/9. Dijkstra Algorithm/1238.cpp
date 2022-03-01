#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321

using namespace std;

struct Data {
    int n, w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};
    bool operator<(const Data d) const {
        return w > d.w;
    }
};

int N, M, X;
int a, b, c;
vector<Data> v[1001][2];
int dist[1001][2];
bool isVisited[1001][2];
priority_queue<Data> pq[2];
int answer;

int main(int argc, char** argv) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            v[i][j].clear();
            dist[i][j] = INF;
            isVisited[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v[a][0].push_back(Data(b, c));
        v[b][1].push_back(Data(a, c));
    }

    for (int k = 0; k < 2; k++) {
        pq[k].push(Data(X, 0));
        dist[X][k] = 0;
        while (true) {
            if (pq[k].empty()) break;
            Data d = pq[k].top();
            pq[k].pop();
            if (isVisited[d.n][k]) continue;
            isVisited[d.n][k] = true;
            Data vi;
            for (int i = 0; i < v[d.n][k].size(); i++) {
                vi = v[d.n][k].at(i);
                if (dist[vi.n][k] > dist[d.n][k] + vi.w) {
                    dist[vi.n][k] = dist[d.n][k] + vi.w;
                    pq[k].push(Data(vi.n, dist[vi.n][k]));
                }
            }
        }
    }

    int answer = -1;
    for (int i = 1; i <= N; i++) {
        answer = max(answer, dist[i][0] + dist[i][1]);
    }

    cout << answer << endl;

    return 0;
}
/*
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
*/
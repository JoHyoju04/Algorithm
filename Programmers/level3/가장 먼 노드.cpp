// 1. Kruskal algorithm
#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int, int> > graph[20001];
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
        for (int i = 0; i < graph[curN].size(); i++) {
            int nextD = curD + graph[curN][i].second;
            int nextN = graph[curN][i].first;
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
        graph[edge[i][0]].push_back({ edge[i][1],1 });
        graph[edge[i][1]].push_back({ edge[i][0],1 });
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

/* 
2. BFS
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[20001];
vector<int> visited;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int max=0;
    visited.assign(n+1,0);
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next=graph[cur][i];
            if(visited[next]==0 &&next!=1){
                visited[next]=visited[cur]+1;
                q.push(next);
                if(max<visited[next]){
                    max=visited[next];
                    answer=1;
                }
                else if(max==visited[next]) answer++;
            }
        }
    }
    return answer;
}
*/
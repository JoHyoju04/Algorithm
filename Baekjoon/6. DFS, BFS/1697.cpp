#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000001
int N, K;
bool visited[MAX];
int BFS(int n, int k) {
    queue<pair<int, int> > que;
    que.push({ N,0 }); //위치,시간
    visited[N] = true;
    while (!que.empty()) {
        int line = que.front().first;
        int time = que.front().second;
        que.pop();
        if (line == K) return time;
        if (2 * line < MAX && !visited[2 * line]) {
            que.push({ 2 * line,time + 1 });
            visited[2 * line] = true;
        }
        if (line + 1 < MAX && !visited[line + 1]) {
            que.push({ line + 1,time + 1 });
            visited[line + 1] = true;
        }
        if (line - 1 >= 0 && !visited[line - 1]) {
            que.push({ line - 1,time + 1 });
            visited[line - 1] = true;
        }
    }
    return 0;
}
int main() {
    cin >> N >> K;
    if (N > K) {
        cout << N - K;
        return 0;
    }
    cout << BFS(N, K);
    return 0;
}
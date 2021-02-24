#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > map(102, vector<int>(102, 0));
vector<bool> visited(102);
int N, E, answer = 0;
void DFS(int start) {
    visited[start] = true;
    for (int i = 1; i <= N; i++) {
        if (!visited[i] && map[start][i]) {
            answer++;
            DFS(i);
        }
    }
}

int main() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        map[n1][n2] = 1;
        map[n2][n1] = 1;
    }
    DFS(1);
    cout << answer;
    return 0;
}
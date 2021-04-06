#include <string>
#include <vector>

using namespace std;
vector<bool> visited;
void dfs(int start, vector<vector<int> > com) {
    visited[start] = 1;
    for (int i = 0; i < com.size(); i++) {
        if (!visited[i] && com[start][i])
            dfs(i, com);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    visited.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}
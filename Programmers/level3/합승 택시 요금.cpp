#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

long long dp[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; i++)   dp[i][i] = 0;

    for (auto v : fares) {
        dp[v[0]][v[1]] = v[2];
        dp[v[1]][v[0]] = v[2];
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF)  continue;
                if (dp[i][k] + dp[k][j] < dp[i][j])  dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        answer = min(answer, dp[s][i] + dp[i][a] + dp[i][b]);

    return answer;
}
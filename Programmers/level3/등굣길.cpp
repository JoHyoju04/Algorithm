#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<long long> > dp(n, vector<long long>(m, 0));
    dp[0][0] = 1;
    for (int i = 0; i < puddles.size(); i++)
        dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -1 || (i == 0 && j == 0))    continue;
            int r = i - 1, c = j - 1;
            if (r >= 0 && r < n && dp[r][j] != -1) dp[i][j] += dp[r][j] % MOD;
            if (c >= 0 && c < m && dp[i][c] != -1) dp[i][j] += dp[i][c] % MOD;
            dp[i][j] %= MOD;
        }
    }
    answer = dp[n - 1][m - 1];
    return answer;
}
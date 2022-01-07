#include<iostream>
using namespace std;
#define MAX 1002
#define MOD 10007

int dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j)    dp[i][j] = 1;
            else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    cout << dp[N][K];

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T, N, M;
    vector<int> coin,dp;

    cin >> T;
    while (T--) {
        cin >> N;
        coin.assign(21,0);
        dp.assign(10001, 0);
        for (int i = 1; i <= N; i++) {
            cin >> coin[i];
        }

        cin >> M;
        dp[0] = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = coin[i]; j <= M; j++)
            {
                dp[j] = dp[j] + dp[j - coin[i]];
            }
        }
        cout <<dp[M] << "\n";
    }
    return 0;
}
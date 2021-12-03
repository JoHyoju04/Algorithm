#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int arr[501][501];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n,answer;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    answer=dp[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)    dp[i][j] = dp[i - 1][0];
            else if (i == j)   dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
            dp[i][j] += arr[i][j];
            if (i == n - 1)  answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
    return 0;
}
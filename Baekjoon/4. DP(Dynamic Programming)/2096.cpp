#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;
int arr[100001][3];

int threeMax(int a, int b, int c) {
    int ret = max(a, b);
    ret = max(ret, c);
    return ret;
}
int threeMin(int a, int b, int c) {
    int ret = min(a, b);
    ret = min(ret, c);
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    int minN = 987654321;
    int maxN = 0;
    vector<vector<int> > dp;
    cin >> N;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    }

    if (N == 1) {
        cout << threeMax(arr[0][0], arr[0][1], arr[0][2]) << " " << threeMin(arr[0][0], arr[0][1], arr[0][2]);
        return 0;
    }
    dp.assign(2, vector<int>(3, 0));
    dp[0][0] = arr[0][0];   dp[0][1] = arr[0][1];   dp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            if (j == 0)    num = max(dp[0][0], dp[0][1]);
            if (j == 1)    num = threeMax(dp[0][0], dp[0][1], dp[0][2]);
            if (j == 2)    num = max(dp[0][1], dp[0][2]);
            dp[1][j] = arr[i][j] + num;
        }
        if (i == N - 1)    maxN = threeMax(dp[1][0], dp[1][1], dp[1][2]);
        dp[0][0] = dp[1][0];   dp[0][1] = dp[1][1];   dp[0][2] = dp[1][2];
    }

    dp.assign(2, vector<int>(3, 0));
    dp[0][0] = arr[0][0];   dp[0][1] = arr[0][1];   dp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int num;
            if (j == 0)    num = min(dp[0][0], dp[0][1]);
            if (j == 1)    num = threeMin(dp[0][0], dp[0][1], dp[0][2]);
            if (j == 2)    num = min(dp[0][1], dp[0][2]);
            dp[1][j] = arr[i][j] + num;
        }
        if (i == N - 1)    minN = threeMin(dp[1][0], dp[1][1], dp[1][2]);

        dp[0][0] = dp[1][0];   dp[0][1] = dp[1][1];   dp[0][2] = dp[1][2];
    }
    
    cout << maxN << " " << minN;

    return 0;
}
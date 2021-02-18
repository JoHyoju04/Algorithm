/*
< 12865 : 평범한 배낭 >
dp[물건 개수][최대 배낭 무게] : 가치

점화식 :
1. 해당 차례의 물건을 담는 경우 : (해당 배낭무게- 해당차례 물건의 무게)의 배낭에 해당 차레 물건의 가치 더하기
   dp[i][j]=dp[i][j-해당차례물건무게]+해당차례 물건 가치

2. 해당 차례의 물건을 담지 않는 경우
   dp[i][j]=dp[i-1][j]

->1과 2중의 최댓값을 선택한다.
*/
#include <iostream>
#include<algorithm>
using namespace std;
int n, k, item[102][2], dp[102][100001];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> item[i][0] >> item[i][1];
    }
    for (int i = 1; i <= n; i++) {
        int weight = item[i][0];
        int value = item[i][1];
        for (int j = 0; j <= k; j++) {
            if (j < item[i][0])    dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
        }
    }
    cout << dp[n][k];

    return 0;
}
/*
< 2294 : 동전2 >
기저 사례
DP[0]=0 :동전의 가치가 0인 동전의 최소개수
DP[1~k]=10001 : min갱신을 위한 최댓값으로 설정,1~k가 되는 동전의 최소개수

점화식 :
DP[j]=min(DP[j],DP[j-coin[j])+1 : 원래 만들 수 있는 동전의 개수와 j-coin[i]에서 coin[i]를 더해 만드는 동전의 개수 중에 최솟값
*/
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int DP[10001] = { 0, };
    int n, k, coin[101];
    int j, i;
    cin >> n >> k;
    for (i = 1; i <= k; ++i)   DP[i] = 10001;
    for (i = 1; i <= n; i++) {
        cin >> coin[i];
        for (j = coin[i]; j <= k; j++) {
            DP[j] = min(DP[j], DP[j - coin[i]] + 1);
        }
    }
    if (DP[k] == 10001)    cout << "-1";
    else cout << DP[k];

    return 0;
}
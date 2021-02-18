/*
< 12865 : ����� �賶 >
dp[���� ����][�ִ� �賶 ����] : ��ġ

��ȭ�� :
1. �ش� ������ ������ ��� ��� : (�ش� �賶����- �ش����� ������ ����)�� �賶�� �ش� ���� ������ ��ġ ���ϱ�
   dp[i][j]=dp[i][j-�ش����ʹ��ǹ���]+�ش����� ���� ��ġ

2. �ش� ������ ������ ���� �ʴ� ���
   dp[i][j]=dp[i-1][j]

->1�� 2���� �ִ��� �����Ѵ�.
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
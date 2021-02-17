/*
< 2294 : ����2 >
���� ���
DP[0]=0 :������ ��ġ�� 0�� ������ �ּҰ���
DP[1~k]=10001 : min������ ���� �ִ����� ����,1~k�� �Ǵ� ������ �ּҰ���

��ȭ�� :
DP[j]=min(DP[j],DP[j-coin[j])+1 : ���� ���� �� �ִ� ������ ������ j-coin[i]���� coin[i]�� ���� ����� ������ ���� �߿� �ּڰ�
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
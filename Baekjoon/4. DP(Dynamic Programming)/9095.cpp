/*
< 9095 : 1,2,3 ���ϱ� >
���� ���
sum[0]=1 : n�� 1�� ��, ����� �� -> 1
sum[1] =2 : n�� 2�� ��, ����� �� -> 1+1,2
sum[2] =4 : n�� 3�� ��, ����� �� -> 1+1+1,2+1,1+2,3

��ȭ�� :
sum[j] =sum[j-1]+sum[j - 2] + score[j-3] : 1�� ���ϸ� �Ǵ� ���(���̰� 1) + 2�� ���ϸ� �Ǵ� ���(���̰� 2) + 3�� ���ϸ� �Ǵ� ���(���̰� 3)

*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t, n;
    vector<int>sum;
    cin >> t;
    while (t--) {
        sum.push_back(1);
        sum.push_back(2);
        sum.push_back(4);
        cin >> n;
        for (int i = 3; i < n; i++)    sum.push_back(sum[i - 1] + sum[i - 2] + sum[i - 3]);
        cout << sum[n - 1] << "\n";
        sum.clear();
    }

    return 0;
}


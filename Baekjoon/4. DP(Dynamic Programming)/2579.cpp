/*
< 1904 : ��ܿ����� >
���� ���
sum[0]=score[0] :ù����� �� ù����� ��� ���
sum[1] = max(score[0]+score[1],score[1]) : �ι�° ����� ��,  ù����� ��� �ι�° ����� ���� ���� �ι�° ��ܸ� ���� ��� �߿� �ִ�
sum[2] = max(score[0]+score[2],score[1]+score[2]) : ����° ����� ��,  ù����� ��� ����° ����� ���� ���� �ι�° ��ܰ� ����° ����� ���� ��� �߿� �ִ�

��ȭ�� :
������ ����� ��� �������� ��ȭ���� �����
sum[j] =sum[j - 2] + score[j] :���� ���(���������)�� ��� �� ���� ����� ��� ���
sum[j] = sum[j - 3] + score[j - 1] + score[j]) : ���� ���(���������)�� ��� �� �� ���, ��������� ��� ���
->�� ��� �� �ִ��� �����Ѵ�.
*/
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    int score[301] = { 0, };
    int sum[301] = { 0, };
    cin >> n;
    for (int i = 0; i < n; i++)    cin >> score[i];
    sum[0] = score[0];
    sum[1] = max(score[0] + score[1], score[1]);
    sum[2] = max(score[0] + score[2], score[1] + score[2]);
    for (int j = 3; j < n; j++) {
        sum[j] = max(sum[j - 2] + score[j], sum[j - 3] + score[j - 1] + score[j]);
    }

    cout << sum[n - 1];
    return 0;
}


/*
< 1149 : RGB�Ÿ� >
[DP]
���� ��� : 
 sum[0][0]=color[0][0]   //0��° ���� ���������� ĥ�� ���
 sum[0][1]=color[0][1]   //0��° ���� �ʷϻ����� ĥ�� ���
 sum[0][2]=color[0][2]   //0��° ���� �Ķ������� ĥ�� ���

��ȭ�� :
 1 ) a��°���� ���������� ĥ�� ���
 sum[a][b]=color[a][b]+min(sum[a-1][1],sum[a-1][2])

 2 ) a��°���� �ʷϻ����� ĥ�� ���
 sum[a][b]=color[a][b]+min(sum[a-1][0],sum[a-1][2])

 2 ) a��°���� �Ķ������� ĥ�� ���
 sum[a][b]=color[a][b]+min(sum[a-1][0],sum[a-1][1])

*/
#include <iostream>
using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}
int main() {
    int N, m = 1000000;
    int color[1001][3] = { 0, };
    int sum[1001][3] = { 0, };
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            cin >> color[i][j];
    }
    sum[0][0] = color[0][0];
    sum[0][1] = color[0][1];
    sum[0][2] = color[0][2];
    for (int a = 1; a < N; a++) {
        for (int b = 0; b < 3; b++) {
            if (b == 0)    sum[a][b] = color[a][b] + min(sum[a - 1][1], sum[a - 1][2]);
            else if (b == 1)   sum[a][b] = color[a][b] + min(sum[a - 1][0], sum[a - 1][2]);
            else sum[a][b] = color[a][b] + min(sum[a - 1][0], sum[a - 1][1]);

            if (a == N - 1) {
                if (m > sum[a][b])    m = sum[a][b];
            }
        }
    }
    cout << m;
    return 0;
}


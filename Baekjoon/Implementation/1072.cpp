#include <bits/stdc++.h>

using namespace std;

#define MAXSIZE 1000000000

long long X, Y;//���� ������ 10�������� 100�� ���ؾ� �ϹǷ� long long���� ����

bool fmin(int v)
{
    //v��ŭ ������ ���� �� �·��� ���ϴ��� Ȯ��
    if (Y * 100 / X < (Y + v) * 100 / (X + v)) return true;
    else return false;
}

int main()
{
    int lb = 0, ub = MAXSIZE, m;
    scanf("%lld %lld", &X, &Y);

    //�·��� 99% �̻��̶��, �Ҽ����� ������ ������ �ƹ��� ������ �����ص� �·��� ������ �ʴ´�.
    if (Y * 100 / X >= 99)
    {
        printf("-1");
        return 0;
    }

    while (lb + 1 < ub)
    {
        m = lb + (ub - lb) / 2;
        if (fmin(m)) ub = m;
        else lb = m;
    }

    printf("%d", ub);

    return 0;
}

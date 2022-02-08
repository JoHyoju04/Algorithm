#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int Data[MAXN + 1];

int main()
{
    int N, S;

    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++) scanf("%d", &Data[i]);

    int left = 0, right = 0, sum = 0, ans = N + 1;

    while (true)
    {
        if (sum >= S)//�κ����� S�̻��̸�...
        {
            ans = min(ans, right - left);
            //left�� ���ְ� left ����Ʈ�� ���������� �ű��.
            sum -= Data[left++];
        }
        else if (right == N) break;//���� �����ϸ� ����
        else
        {
            //�κ����� S �̸��� ��� right�� �����ְ� right ����Ʈ�� ���������� �ű��.
            sum += Data[right++];
        }
    }

    printf("%d", ans == N + 1 ? 0 : ans);

    return 0;
}
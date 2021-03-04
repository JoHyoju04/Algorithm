#include<iostream>
#include<algorithm>
using namespace std;
long long n, k;

long long func(long long mid) // mid�� �ε����� ���ϴ� �Լ�
{
	long long cnt = 0;
	for (long long i = 1; i <= n; i++)
	{ // ���� ����(mid)���� �۰ų� ���� ���� ������ count
		cnt += min(n, mid / i);
	}
	return cnt; // mid�� �ε���
}

int main(void)
{
	cin >> n >> k;

	long long left = 1;
	long long right = n * n;
	long long ans = 1;
	while (left <= right)
	{
		long long mid = (left + right) / 2; // ���� ����

		if (func(mid) >= k) // ���� ������ �ε����� �� ũ�ٸ�
		{
			ans = mid;
			right = mid - 1; // ���� ���Ҹ� ���ҽ��� Ȯ��
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << ans << '\n';
}

"""
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<memory.h>
using namespace std;

int num[10][9] =
{
	 { 1,1,1,1,1,1,0 },
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1}
	,{0,1,1,0,0,1,1}
	,{1,0,1,1,0,1,1}
	,{1,0,1,1,1,1,1}
	,{1,1,1,0,0,0,0}
	,{1,1,1,1,1,1,1}
	,{1,1,1,1,0,1,1}
};

vector<int> v;
vector<int> v2;
int n, k, p, x;
long long ans;
void solution();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k >> p >> x;
	solution();
	cout << ans;
}

int getDiffOne(int a, int b)
{
	int cnt = 0;
	for (int i = 0; i < 7; i++)
	{
		if (num[a][i] != num[b][i])
			cnt++;
	}
	return cnt;
}

int getDiff(int x, int y)
{
	int ret = 0;
	for (int i = 0; i < k; i++)
	{
		ret += getDiffOne(x % 10, y % 10);
		x /= 10;
		y /= 10;
	}
	return ret;
}

void solution()
{
	for (int i = 1; i <= n; i++)
	{
		if (i == x)
			continue;
		if (getDiff(i, x) <= p)
			ans++;
	}
}
"""

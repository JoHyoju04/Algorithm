#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int inf = 1000000000;
typedef long long ll;
int map[11][11]

int main()
{
	int n, m;

	cin>>n>>m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin>>map[i][j];

	int ret = -1;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int di = -n; di < n; ++di)
				for (int dj = -m; dj < m; ++dj)
				{
					if (di == 0 && dj == 0) continue;

					int t = 0, ni = i, nj = j;
					while (ni >= 0 && ni < n && nj >= 0 && nj < m)
					{
						t = 10 * t + map[ni][nj];
						if (fabs(sqrt(t) - (int)sqrt(t)) < 1e-10) ret = max(ret, t);
						ni += di;
						nj += dj;
					}
					
				}

	cout << ret << '\n';
	return 0;
}
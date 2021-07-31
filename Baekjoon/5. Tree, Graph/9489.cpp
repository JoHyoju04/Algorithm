#include <iostream>
using namespace std;

int main() {
	while (1) {
		int n, k, a[1111] = { -1 }, p[1111] = { -1 };
		cin >> n >> k;
		if (n==0) break;

		int cnt = -1, idx = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (a[i] == k) idx = i;
			if (a[i] != a[i - 1] + 1) cnt++;
			p[i] = cnt;
		}

		int answer = 0;
		for (int i = 1; i <= n; i++)
			if (p[i] != p[idx] && p[p[i]] == p[p[idx]]) answer++;

		cout << answer << "\n";
	}

	return 0;
}
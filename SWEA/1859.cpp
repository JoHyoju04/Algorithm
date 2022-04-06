#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case) {
		int N;
		long long answer = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		int idx = N - 1, i = idx - 1;
		while (idx > 0) {
			for (i = idx - 1; i >= 0; i--) {
				if (arr[idx] < arr[i]) {
					idx = i;
					break;
				}
				else answer += arr[idx] - arr[i];
			}
			if (i < 0)	break;

		}
		for (int i = 0; i < N; i++) {
			arr[i];
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
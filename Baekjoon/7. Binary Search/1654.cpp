#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long len[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	long long N, K, answer = 0, sum = 0, max = 0;
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> len[i];
		max = max > len[i] ? max : len[i];
	}
	long long low = 1, high = max;
	while (low <= high) {
		sum = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < K; i++) {
			sum += len[i] / mid;
		}
		if (sum >= N) {
			answer = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}
	cout << answer;
	return 0;
}
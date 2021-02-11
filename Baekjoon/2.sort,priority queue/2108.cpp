#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int N, mode, idx;
	double sum = 0;
	cin >> N;
	vector<int> arr(N);
	vector<int> cnt(500000);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		cnt[arr[i] + 4000]++;
	}
	sum = round(sum / arr.size());
	if (sum == -0)	sum = 0;
	mode = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	if (*max_element(cnt.begin(), cnt.end()) == *max_element(cnt.begin() + mode + 1, cnt.end()))	mode = max_element(cnt.begin() + mode + 1, cnt.end()) - cnt.begin();
	mode -= 4000;

	sort(arr.begin(), arr.end());
	cout << sum << "\n" << arr[arr.size() / 2] << "\n" << mode << "\n" << arr.back() - arr.front();
}
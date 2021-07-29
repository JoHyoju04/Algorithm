#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(NULL);	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	vector<int> arr;
	cin >> n >> m;
	arr.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start>> end;
		auto sIter = lower_bound(arr.begin(), arr.end(), start);
		auto eIter = lower_bound(arr.begin(), arr.end(), end);
		if (sIter == arr.end())	cout << "0";
		else if (eIter == arr.end()||arr[eIter - arr.begin()] > end)	cout << eIter - sIter;
		else cout << eIter - sIter + 1;
		cout << "\n";
	}

	return 0;
}
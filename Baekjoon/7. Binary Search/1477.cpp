#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, l;
	cin >> n >> m >> l;
	vector<int> store;
	int pos;
	store.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> pos;
		store.push_back(pos);
	}
	store.push_back(l);
	sort(store.begin(),store.end());

	int left = 1;
	int right = l - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int new_store = 0;
		for (int i = 1; i < store.size(); i++) {
			int dist = store[i] - store[i - 1];
			new_store += (dist / mid);
			if (dist % mid == 0) new_store--;
		}
		if (new_store > m)    left = mid + 1;
		else right = mid - 1;
	}
	cout << left;

	return 0;
}
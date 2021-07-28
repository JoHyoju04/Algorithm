#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[101];
vector<bool> visited;
vector<int> result;

void dfs(int current, int start) {
	if (visited[current]) {
		if (current == start)
			result.push_back(start);
	}
	else {
		visited[current] = 1;
		dfs(arr[current], start);
	}

}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		visited.assign(n + 1, 0);
		dfs(i, i);
	}

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}
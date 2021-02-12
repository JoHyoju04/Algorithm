#include <iostream>
using namespace std;
void count(int n) {
	int two[41] = { 0, }, zero[41] = { 0, };
	zero[0] = 1, two[0] = 0;
	if (n > 0) {
		zero[1] = 0, two[1] = 1;
		for (int i = 2; i <= n; i++) {
			zero[i] = zero[i - 1] + zero[i - 2];
			two[i] = two[i - 1] + two[i - 2];
		}
	}
	cout << zero[n] << " " << two[n] << "\n";
}
int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		count(n);
	}
}
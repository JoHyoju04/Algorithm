#include <iostream>
#include <cmath>
using namespace std;
int N, result, col[15] = { 0, };
bool promising(int i) {
	int k = 1;
	bool sw = true;
	while (i > k&& sw) {
		if (col[i] == col[k] || abs(col[i] - col[k]) == i - k)
			sw = false;
		k++;
	}
	return sw;

}
void queens(int i) {
	if (promising(i)) {
		if (i == N)
			result++;
		else {
			for (int j = 1; j <= N; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
}
int main() {
	cin >> N;
	queens(0);
	cout << result;
}

#include <iostream>
using namespace std;
int main() {
	int K, num, top = -1, sum = 0, array[1000001] = { 0, };
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> num;
		if (num != 0)
			array[++top] = num;
		else
			array[top--] = 0;
	}
	for (int j = 0; j <= top; j++)
		sum += array[j];
	cout << sum;
}
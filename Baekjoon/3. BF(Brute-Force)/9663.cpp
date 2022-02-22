#include <bits/stdc++.h>

using namespace std;

#define MAXN 15

int Col[MAXN];
int N, Ans = 0;

bool check(int row)
{
	for (int i = 0; i < row; i++)
	{
		if (Col[i] == Col[row] || abs(Col[row] - Col[i]) == row - i)
			return false;
	}
	return true;
}

void backtracking(int c)
{
	if (c == N)
	{
		Ans++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		Col[c] = i;
		if (check(c)) backtracking(c + 1);
	}
}
int main()
{
	scanf("%d", &N);

	backtracking(0);

	printf("%d", Ans);
}
/*
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
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int N, sum = 0;
	int time[1001] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> time[i];
	sort(time, time + N);
	int answer = 0;
	for (int i = 0; i < N; i++) {
		sum = (time[i] + sum);
		answer += sum;
	}
	cout << answer;
	return 0;
}

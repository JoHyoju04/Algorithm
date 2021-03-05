/*
< 1931 : 회의실 배정 >
끝나는 시간을 기준으로 오름차순으로 정렬
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, before = 0, answer = 0;
	vector<pair<int, int> > time;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		time.push_back({ end,start });
	}
	sort(time.begin(), time.end());
	for (int i = 0; i < N; i++) {
		if (before <= time[i].second) {
			before = time[i].first;
			answer++;
		}
	}
	cout << answer;
	return 0;
}

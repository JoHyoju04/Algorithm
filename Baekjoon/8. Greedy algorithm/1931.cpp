#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)  return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, answer = 0;
    vector<pair<int, int> > times;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        times.push_back({ s,e });
    }
    sort(times.begin(), times.end(), cmp);
    int end = 0;
    for (int i = 0; i < N; i++) {
        if (end <= times[i].first) {
            end = times[i].second;
            answer++;
        }
    }
    cout << answer;
    return 0;
}
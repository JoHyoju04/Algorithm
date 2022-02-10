#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
int N, K, answer;
int A[11];

void go() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, K }); // 시도횟수, 0으로 가기 위해 남은 값
    while (pq.top().second) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cnt = cur.first;
        int left = cur.second;

        pq.push({ cur.first + cur.second, 0 }); // 더이상 나눌 수 있는 값이 없어서 현재 수에서 계속 빼야 하는 경우
        for (int i = 0; i < N; i++) {
            pq.push({ cnt + left % A[i], left / A[i] }); // 나눌 수 없는 나머지는 더해야하는 값.
        }
    }
    answer = pq.top().first;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        cin >> K;
        go();

        cout << "#" << test_case << " " << answer << "\n";

    }
    return 0;
}
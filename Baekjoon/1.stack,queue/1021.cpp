#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> dq;
    int target, answer = 0;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)   dq.push_back(i);
    for (int a = 0; a < M; a++) {
        cin >> target;
        for (int b = 0; b < dq.size(); b++) {
            if (target == dq[b]) {
                target = b;
                break;
            }
        }
        while (target != 0) {
            if (target <= dq.size() / 2) {
                dq.push_back(dq.front());
                dq.pop_front();
                target = (target - 1) % dq.size();
            }
            else {
                dq.push_front(dq.back());
                dq.pop_back();
                target = (target + 1) % dq.size();
            }
            answer++;
        }
        if (target == 0)   dq.pop_front();
    }
    cout << answer;
    return 0;
}
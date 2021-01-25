#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b) {
    return a > b;
}
int solution(vector<int> priorities, int location) {
    int answer = 0, max_idx = 0, front = -1;
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end(), compare);
    while (true) {
        front = (front + 1) % priorities.size();
        if (priorities[front] == sorted[max_idx]) {
            answer++;
            max_idx++;
            if (location == front)
                break;
        }
    }
    return answer;
}
int main() {
    int TC, N, M;
    vector<int> printer;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            printer.push_back(num);
        }
        cout << solution(printer, M) << endl;
        printer.clear();
    }

}
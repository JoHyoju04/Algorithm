#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int N;
    stack<int> s;
    vector<int> A;
    cin >> N;
    vector<int> answer(N, -1);
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        A.push_back(num);
    }
    for (int j = 0; j < N; j++) {
        while (!s.empty() && A[s.top()] < A[j]) {
            answer[s.top()] = A[j];
            s.pop();
        }
        s.push(j);
    }
    for (int k = 0; k < N; k++) {
        cout << answer[k] << " ";
    }
    return 0;
}
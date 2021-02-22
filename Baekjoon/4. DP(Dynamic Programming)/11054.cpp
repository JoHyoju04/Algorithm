#include <iostream>
#include <vector>
using namespace std;
int N, maximum = 0;
vector <int> A(1000);
vector<int> increaseCnt(1000);
vector<int> decreaseCnt(1000);
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = i - 1; j >= 0; j--) {
            if (A[i] > A[j] && increaseCnt[i] < increaseCnt[j])
                increaseCnt[i] = increaseCnt[j];
        }
        increaseCnt[i]++;
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j] && decreaseCnt[i] < decreaseCnt[j])
                decreaseCnt[i] = decreaseCnt[j];
        }
        decreaseCnt[i]++;
    }
    for (int i = 0; i < N; i++) {
        maximum = increaseCnt[i] + decreaseCnt[i] < maximum ? maximum : increaseCnt[i] + decreaseCnt[i];
    }
    cout << maximum - 1;
    return 0;
}
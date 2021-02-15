#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> A(1000);
vector<int> list(1000);
int main() {
    int N, size = 0;
    cin >> N;
    for (int i = 0; i < N; i++)    cin >> A[i];
    list[0] = A[0];
    for (int j = 1; j < N; j++) {
        for (int k = size; k >= 0; k--) {
            if (list[k] < A[j]) {
                list[k + 1] = A[j];
                size = size < k + 1 ? k + 1 : size;
                break;
            }
            else if (k == 0)   list[k] = A[j];
        }
    }
    int answer = find(list.begin(), list.end(), 0) - list.begin();
    cout << answer;
    return 0;
}


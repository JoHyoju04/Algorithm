#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr(10001);

int main() {
    int N, M, sum, max = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max = max > arr[i] ? max : arr[i];
    }
    cin >> M;
    int low = 1, high = M;
    int answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        sum = 0;
        for (int i = 0; i < N; i++) {
            if (mid > arr[i]) sum += arr[i];
            else
            {
                sum += mid;
                max = mid;
            }
        }
        if (sum > M) {
            high = mid - 1;
        }
        else {
            answer = max;
            low = mid + 1;
        }
    }
    cout << answer;
    return 0;
}
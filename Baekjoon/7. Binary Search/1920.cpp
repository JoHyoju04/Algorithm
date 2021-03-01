#include <iostream>
#include <algorithm>
using namespace std;
int nums[100001];
long N, M, K;
bool search(int low, int high, int key) {
    while (low <= high) {
        int mid = (high + low) / 2;
        if (nums[mid] == key)  return true;
        else if (nums[mid] < key)  low = mid + 1;
        else if (nums[mid] > key)  high = mid - 1;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + N);
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> K;
        if (search(0, N - 1, K)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define MAX 2000000000
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, minN = MAX;
    vector<int> answer(2);
    vector<int> arr;
    cin >> N;
    arr.assign(N, 0);

    for (int i = 0; i < N; i++)    cin >> arr[i];
    sort(arr.begin(), arr.end());

    int low = 0, high = N - 1;
    while (low < high) {
        if (abs(arr[low] + arr[high]) < minN) {
            minN = abs(arr[low] + arr[high]);
            answer[0] = arr[low];
            answer[1] = arr[high];
        }
        if (arr[low] + arr[high] > 0)    high--;
        else if (arr[low] + arr[high] < 0)   low++;
        else break;
    }
    cout << answer[0] <<" " <<answer[1];
    return 0;

}
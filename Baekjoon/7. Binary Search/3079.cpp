#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<long long> time, int m, long long mid) {
    long long sum = 0;
    for (int i = 0; i < time.size(); i++) {
        sum += mid / time[i];
    }
    if (sum < m)   return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    vector<long long> time;
    cin >> N >> M;
    time.assign(N, 0);
    for (int i = 0; i < N; i++)    cin >> time[i];

    long long low = *min_element(time.begin(), time.end());
    long long high = *max_element(time.begin(), time.end())*M;
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (check(time, M, mid)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low;
    return 0;
}
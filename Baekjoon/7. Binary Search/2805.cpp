#include <iostream>
#include <algorithm>
using namespace std;
int tree[1000001];
long long N, M;
long long sum = 0, m = 0, result = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> tree[i];
        if (m < tree[i]) m = tree[i];
    }
    long long high = m;
    long long low = 0;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long total = 0;
        for (int i = 0; i < N; i++)
            if (mid < tree[i])
                total += tree[i] - mid;

        if (total >= M) {
            if (result < mid)
                result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }

    }
    cout << result;
    return 0;
}
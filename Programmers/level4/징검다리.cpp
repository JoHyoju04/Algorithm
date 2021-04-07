#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_possible(int distance, vector<int> rocks, int n, int min_dist) {
    int gap, last = -1, removed = 0;
    for (int i = 0; i <= rocks.size(); ++i) {
        gap = (last == -1 ? rocks[i] : (i == rocks.size() ? distance - rocks.back() : rocks[i] - rocks[last]));
        if (gap < min_dist) { removed++; }
        else { last = i; }
    }
    return removed <= n;
}
int solution(int distance, vector<int> rocks, int n) {
    int low = 0, high = distance, mid;
    sort(rocks.begin(), rocks.end());
    while (low + 1 < high) {
        mid = (low + high) / 2;
        if (is_possible(distance, rocks, n, mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return low;
}
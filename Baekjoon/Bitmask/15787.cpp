#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    cin.tie(NULL);   cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1, 0);
    while (m--) {
        int num,idx, seat;
        cin >> num;
        switch (num) {
            case 1:
                cin >> idx >> seat;
                v[idx] |= (1 << (seat - 1));
                break;
            case 2:
                cin >> idx >> seat;
                v[idx] &= ~(1 << (seat - 1));
                break;
            case 3:
                cin >> idx;
                v[idx] = v[idx] << 1;
                v[idx] &= ((1 << 20) - 1);
                break;
            default:
                cin >> idx;
                v[idx] = v[idx] >> 1;
                break;
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(v[i]);
    }
    cout << s.size();

    return 0;
}

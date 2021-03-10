#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num;
    vector<int> v(1, 1000001);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (v.back() < num) {
            v.push_back(num);
        }
        else {
            auto iter = lower_bound(v.begin(), v.end(), num);
            *iter = num;
        }
    }

    cout << v.size();
    return 0;
}
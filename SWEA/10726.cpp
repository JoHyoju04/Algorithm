#include<iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    int TC;
    cin >> TC;
    for (test_case = 1; test_case <= TC; ++test_case) {
        int N, M;
        cin >> N >> M;
        cout << '#' << test_case << ' ' << (((M + 1) ^ M) >= (1 << (N + 1)) - 1 ? "ON" : "OFF") << '\n';
    }
    return 0;
}
#include<iostream>
#include<algorithm>
using namespace std;
int apt[1001];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, answer = 0, maxLen = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> apt[i];
        }

        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0) maxLen = max(maxLen, apt[i - 1]);
            if (i - 2 >= 0) maxLen = max(maxLen, apt[i - 2]);
            if (i + 1 < n) maxLen = max(maxLen, apt[i + 1]);
            if (i + 2 < n) maxLen = max(maxLen, apt[i + 2]);

            if (apt[i] > maxLen) answer += apt[i] - maxLen;

            maxLen = 0;
        }

        cout << "#" << test_case << " " << answer << "\n";

        for (int i = 0; i < n; i++) {
            apt[i] = 0;
        }

    }
    return 0;
}
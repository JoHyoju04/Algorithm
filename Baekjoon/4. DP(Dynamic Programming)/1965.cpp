#include<iostream>
using namespace std;
int box[1001];
int cnt[1001];

int main()
{
    int n, answer = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> box[i];
        int max = 0;
        if (i == 0) {
            cnt[0] = 1;
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (box[i] > box[j]) {
                max = max > cnt[j] ? max : cnt[j];
            }
        }
        cnt[i] = 1 + max;
        answer = answer > cnt[i] ? answer : cnt[i];
    }
    cout << answer;
    return 0;
}
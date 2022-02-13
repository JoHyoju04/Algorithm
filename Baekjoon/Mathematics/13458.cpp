#include<iostream>
using namespace std;

int people[1000001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, B, C;
    long long answer = 0;
    cin >> N;
    for (int i = 0; i < N; i++)    cin >> people[i];
    cin >> B >> C;
    for (int i = 0; i < N; i++) {
        long long remain = (long long)people[i] - B;
        if (remain <= 0) {
            remain = 0;
        }
        else {
            if (remain % C == 0)  remain = remain / C;
            else remain = remain / C + 1;
        }

        answer += 1 + remain;
    }
    cout << answer;
    return 0;
}
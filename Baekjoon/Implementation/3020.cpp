#include<iostream>
#include <string>
using namespace std;

int top[500001];
int bottom[500001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, H;
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (i % 2 == 0)  bottom[num]++;
        else top[H - num + 1]++;

    }
    for (int i = 2; i <= H; i++) {
        top[i] += top[i - 1];
        bottom[H - i + 1] += bottom[H - i + 2];
    }
    int minCnt = 200000, answer = 0;
    for (int i = 1; i <= H; i++) {
        if (minCnt > top[i] + bottom[i]) {
            answer = 1;
            minCnt = top[i] + bottom[i];
        }
        else if (minCnt == top[i] + bottom[i])   answer++;
    }
    cout << minCnt << " " << answer;
    return 0;
}
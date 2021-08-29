#include <iostream>
using namespace std;

bool broken[100001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,K, B;
    cin >> N >> K >> B;
    for (int i = 0; i < B; i++) {
        int num;
        cin >> num;
        broken[num-1] = 1;
    }
    
    int minCnt, cnt = 0, low = 0, high = K - 1;
    for (int i = 0; i < K; i++) {
        if (broken[i])   cnt++;
    }
    minCnt = cnt;

    while (high < N - 1) {
        if (broken[low++])   cnt--;
        if (broken[++high])  cnt++;
        minCnt = minCnt < cnt ? minCnt : cnt;
    }
    cout << minCnt;

    return 0;
}
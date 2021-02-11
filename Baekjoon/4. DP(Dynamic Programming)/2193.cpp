#include<iostream>
using namespace std;
int main()
{
    int N;  cin >> N;
    long long cnt[91][2] = { {0,0},{0,1},{1,0} };
    for (int i = 2; i <= N; i++) {
        cnt[i][0] = cnt[i - 1][0] + cnt[i - 1][1];
        cnt[i][1] = cnt[i - 1][0];
    }
    cout << cnt[N][0] + cnt[N][1];
    return 0;
}
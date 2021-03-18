#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int N, M, cnt = 0, min = 64;
    vector<string> board(50);
    vector<string>chess = { "BWBWBWBW",
                        "WBWBWBWB",
                        "BWBWBWBW",
                        "WBWBWBWB",
                        "BWBWBWBW",
                        "WBWBWBWB",
                        "BWBWBWBW",
                        "WBWBWBWB" };
    cin >> N >> M;
    for (int i = 0; i < N; i++)    cin >> board[i];

    for (int i = 0; i <= N - 8; i++) {
        for (int j = 0; j <= M - 8; j++) {
            cnt = 0;
            for (int k = 0; k < 8; k++) {
                for (int t = 0; t < 8; t++) {
                    if (chess[k].at(t) != board[i + k].at(j + t))    cnt++;
                }
            }
            cnt = cnt < 64 - cnt ? cnt : 64 - cnt;
            min = min < cnt ? min : cnt;
        }
    }
    cout << min;
    return 0;
}
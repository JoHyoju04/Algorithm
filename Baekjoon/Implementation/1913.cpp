#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int arr[999][999];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, num;
    cin >> N >> num;
    int cnt = 1;
    int r = N / 2;
    int c = N / 2;
    arr[r][c] = cnt;

    for (int i = 3; i < 3 + N / 2; i++) {
        for (int j = 0; j < 5; j++) {
            int dr = dir[j % 4][0];
            int dc = dir[j % 4][1];
            if (j == 0) {
                r += dr;
                c += dc;
                arr[r][c] = ++cnt;
            }
            else if (j == 1) {
                for (int k = 0; k < (i - 3) * 2 + 1; k++) {
                    r += dr;
                    c += dc;
                    arr[r][c] = ++cnt;
                }
            }
            else {
                for (int k = 0; k < (i - 2) * 2; k++) {
                    r += dr;
                    c += dc;
                    arr[r][c] = ++cnt;
                }
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (num == arr[i][j]) {
                r = i + 1;
                c = j + 1;
            }
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << r << " " << c;
    return 0;
}
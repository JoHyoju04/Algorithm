#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, T;
int map[51][51];
bool check[51][51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int answer = 0;

    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;

        //rotate
        if (d == 0) {   //시계방향
            for (int i = x; i <= N; i += x) {
                for (int r = 0; r < k; r++) { //k칸 움직이기
                    int tmp = map[i][0];
                    for (int j = M - 1; j >= 1; j--) {
                        map[i][(j + 1) % M] = map[i][j];
                    }
                    map[i][1] = tmp;
                }
            }
        }
        else {  //반시계
            for (int i = x; i <= N; i += x) {
                for (int r = 0; r < k; r++) {
                    int tmp = map[i][0];
                    for (int j = 1; j < M; j++) {
                        map[i][(j - 1) % M] = map[i][j];
                    }
                    map[i][M - 1] = tmp;
                }
            }
        }


        bool flag = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0)     flag = true;
            }
        }
        if (!flag)   break;

        //인접한 수 찾기
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0)    continue;
                int num = map[i][j];
                int before = j - 1;
                int after = j + 1;
                if (before < 0)    before = M - 1;
                if (after == M)    after = 0;
                if (num == map[i][before]) {
                    check[i][before] = true;
                    check[i][j] = true;
                }
                if (num == map[i][after]) {
                    check[i][after] = true;
                    check[i][j] = true;
                }

            }
        }

        for (int j = 0; j < M; j++) {
            for (int i = 1; i < N; i++) {
                if (map[i][j] == 0)    continue;
                int num = map[i][j];
                if (num == map[i + 1][j]) {
                    check[i][j] = true;
                    check[i + 1][j] = true;
                }
            }
        }

        //갱신
        int sum = 0, cnt = 0;
        flag = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (check[i][j]) {
                    flag = true;
                    map[i][j] = 0;
                }
                sum += map[i][j];
                if (map[i][j] != 0)    cnt++;
            }
        }

        //초기화
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                check[i][j] = 0;
            }
        }

        if (flag) {
            answer = sum;
            continue;
        }

        double avg = (double)sum / (double)cnt;
        sum = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0) continue;
                double n = map[i][j];
                if (avg < n)   map[i][j] -= 1;
                else if (avg > n)  map[i][j] += 1;
                sum += map[i][j];
            }
        }
        answer = sum;

    }

    cout << answer;
    return 0;
}
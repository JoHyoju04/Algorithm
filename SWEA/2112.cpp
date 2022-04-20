#include<iostream>
using namespace std;

int cell[14][21];
int answer, D, W, K;

void dfs(int cnt, int idx) {

    //약품투입 횟수는 K를 넘지 않는다.
    if (cnt > K)	return;

    int succ = 0;
    for (int i = 0; i < W; i++) {
        int cnt = 1, num = cell[0][i];
        bool flag = false;

        for (int j = 1; j < D; j++) {
            if (cell[j][i] == num) cnt++;
            else {
                cnt = 1;
                num = cell[j][i];
            }

            if (cnt == K) {
                flag = true;
                break;
            }
        }

        //한 열이라도 연속으로 없으면(flag가 false이면) for문 바로 벗어나기
        if (flag)    succ++;
        else break;
    }

    if (succ == W) {
        answer = answer < cnt ? answer : cnt;
        return; //성능검사 통과하면 바로 return 해준다.
    }

    for (int i = idx; i < D; i++) {
        int tmp[21];

        for (int j = 0; j < W; j++) {
            tmp[j] = cell[i][j];
        }

        for (int j = 0; j < W; j++) {
            cell[i][j] = 0;
        }
        dfs(cnt + 1, i + 1);

        for (int j = 0; j < W; j++) {
            cell[i][j] = 1;
        }
        dfs(cnt + 1, i + 1);

        for (int j = 0; j < W; j++) {
            cell[i][j] = tmp[j];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {

        cin >> D >> W >> K;
        answer = 987654321;
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cin >> cell[i][j];
            }
        }

        dfs(0, 0);

        cout << "#" << test_case << " "<<answer<< "\n";

        for (int i = 0; i < D; i++) {
            for (int j = 0; j < W; j++) {
                cell[i][j] = 0;
            }
        }


    }
    return 0;
}
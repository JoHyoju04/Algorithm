#include<iostream>
using namespace std;

int cell[14][21];
int answer, D, W, K;

void dfs(int cnt, int idx) {

    //��ǰ���� Ƚ���� K�� ���� �ʴ´�.
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

        //�� ���̶� �������� ������(flag�� false�̸�) for�� �ٷ� �����
        if (flag)    succ++;
        else break;
    }

    if (succ == W) {
        answer = answer < cnt ? answer : cnt;
        return; //���ɰ˻� ����ϸ� �ٷ� return ���ش�.
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
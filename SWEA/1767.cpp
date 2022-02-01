#include <iostream>
#include <vector>
using namespace std;
int T, N;
int coreNum;
int maxDone;
int cell[13][13];
int answer;

void dfs(int count, int done, vector<pair<int, int>> v) {
    if (count == coreNum) {
        int temp = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (cell[i][j] == 2)
                    temp++;
            }
        }
        if (done > maxDone) {
            maxDone = done;
            answer = temp;
        }
        else if (done == maxDone)	answer = answer < temp ? answer : temp;
        return;
    }

    int y = v[count].first;
    int x = v[count].second;

    if (y == 0 || y == N - 1 || x == 0 || x == N - 1)
        dfs(count + 1, done + 1, v);
    else {

        //╩С
        bool flag = true;
        for (int i = 0; i < y; i++) {
            if (cell[i][x] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < y; i++) {
                cell[i][x] = 2;
            }
            dfs(count + 1, done + 1, v);
            for (int i = 0; i < y; i++) {
                cell[i][x] = 0;
            }
        }
        //го
        flag = true;
        for (int i = y + 1; i < N; i++) {
            if (cell[i][x] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = y + 1; i < N; i++)
                cell[i][x] = 2;
            dfs(count + 1, done + 1, v);
            for (int i = y + 1; i < N; i++)
                cell[i][x] = 0;
        }

        //аб
        flag = true;
        for (int i = 0; i < x; i++) {
            if (cell[y][i] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < x; i++)
                cell[y][i] = 2;
            dfs(count + 1, done + 1, v);
            for (int i = 0; i < x; i++)
                cell[y][i] = 0;
        }

        //©Л
        flag = true;
        for (int i = x + 1; i < N; i++) {
            if (cell[y][i] != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = x + 1; i < N; i++)
                cell[y][i] = 2;
            dfs(count + 1, done + 1, v);
            for (int i = x + 1; i < N; i++)
                cell[y][i] = 0;
        }

        dfs(count + 1, done, v);
    }
}

int main(void) {
    cin >> T;
    for (int casenum = 1; casenum <= T; casenum++) {
        cin >> N;

        vector<pair<int, int>> core;
        coreNum = 0;
        maxDone = 0;
        answer = 200;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cell[i][j] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cell[i][j];
                if (cell[i][j] == 1) {
                    coreNum++;
                    core.push_back({ i,j });
                }
            }
        }

        dfs(0, 0, core);

        cout << "#" << casenum << " " << answer << "\n";
    }
}

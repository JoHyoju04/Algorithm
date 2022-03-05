#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
int matrix[19][19];

bool wflag = false;
bool bflag = false;
int answery, answerx;

bool check(int y, int x, int color) {
    int direction[4][2] = { -1, 1, 0, 1, 1, 1, 1, 0 };
    int count = 1;

    for (int i = 0; i < 4; i++) {
        int ny = y + direction[i][0];
        int nx = x + direction[i][1];
        count = 1;
        while (1) {
            if (ny < 0 || ny >= 19 || nx < 0 || nx >= 19) break;

            if (matrix[ny][nx] != color) {
                break;
            }
            count++;
            ny = ny + direction[i][0];
            nx = nx + direction[i][1];
        }
        if (count == 5) {
            answery = y;
            answerx = x;
            return true;
        }
    }
    return false;
}


int main() {
    queue<pair<int, int>> bq;
    queue<pair<int, int>> wq;
    int y, x;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (matrix[i][j] == 1) {
                bq.push({ i, j });
            }
            else if (matrix[i][j] == 2) {
                wq.push({ i, j });
            }
        }
    }

    while (bq.size()) {
        y = bq.front().first;
        x = bq.front().second;
        bq.pop();
        bool temp = check(y, x, 1);
        if (temp) {
            bflag = true;
            break;
        }
    }

    while (wq.size()) {
        y = wq.front().first;
        x = wq.front().second;
        wq.pop();
        if (y == 10 && x == 5) {
            int fd = 1;
        }
        bool temp = check(y, x, 2);
        if (temp) {
            wflag = true;
            break;
        }
    }


    if ((bflag == true && wflag == true) || (bflag == false && wflag == false)) {
        cout << 0;
    }
    else if (bflag) {
        cout << 1 << endl << answery + 1 << " " << answerx + 1;
    }
    else if (wflag) {
        cout << 2 << endl << answery + 1 << " " << answerx + 1;
    }

    return 0;
}
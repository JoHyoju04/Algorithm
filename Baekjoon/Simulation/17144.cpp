#include<iostream>
#include<vector>
using namespace std;

struct dust {
    int r, c, con;
};

int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };
int R, C, T;
int map[51][51];
vector<dust> list;
vector<vector<int> > machin;

void spread() {
    for (int i = 0; i < list.size(); i++) {
        int curR = list[i].r;
        int curC = list[i].c;
        int curCon = list[i].con;

        for (int j = 0; j < 4; j++) {
            int nextR = curR + dir[j][0];
            int nextC = curC + dir[j][1];
            if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C || map[nextR][nextC] == -1)   continue;
            map[curR][curC] -= curCon / 5;
            map[nextR][nextC] += curCon / 5;

        }

    }
}

void counterCircleRotate() {
    int r = machin[0][0];
    int c = machin[0][1];
    map[r - 1][c] = 0;
    for (r -= 2; r >= 0; r--) {
        map[r + 1][c] = map[r][c];
    }
    r = 0;
    for (c += 1; c < C; c++) {
        map[r][c - 1] = map[r][c];
    }
    c = C - 1;
    for (r += 1; r <= machin[0][0]; r++) {
        map[r - 1][c] = map[r][c];
    }
    r = machin[0][0];
    for (c -= 1; c >= machin[0][1] + 1; c--) map[r][c + 1] = map[r][c];
    map[r][machin[0][1] + 1] = 0;

}

void circleRotate() {
    int r = machin[1][0];
    int c = machin[1][1];
    map[r + 1][c] = 0;
    for (r += 2; r < R; r++)   map[r - 1][c] = map[r][c];
    r = R - 1;
    for (c += 1; c < C; c++)    map[r][c - 1] = map[r][c];
    c = C - 1;
    for (r -= 1; r >= machin[1][0]; r--) {
        map[r + 1][c] = map[r][c];

    }
    r = machin[1][0];
    for (c -= 1; c >= machin[1][1] + 1; c--) map[r][c + 1] = map[r][c];
    map[r][machin[1][1] + 1] = 0;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int sum = 0;
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1)   machin.push_back({ i,j });
        }
    }
    for (int t = 0; t < T; t++) {
        list.clear();
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (map[i][j] > 0 && map[i][j] >= 5)   list.push_back({ i,j,map[i][j] });
            }
        }
        spread();
        counterCircleRotate();
        circleRotate();
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] != -1) sum += map[i][j];
        }
    }
    cout << sum;
    return 0;
}
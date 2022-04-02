#include <iostream>
#include <cstring>
using namespace std;

struct snail {
    //좌표
    int x, y;
    //방향
    int dir;
    //숫자
    int num;
};

//동,남,서,북
int di[] = { 0,1,0,-1 };
int dj[] = { 1,0,-1,0 };

int N;
int map[12][12];

void go(snail cur) {

    //종료조건 : 숫자를 다 채웠을 경우
    if (cur.num > N* N) {
        return;
    }

    map[cur.x][cur.y] = cur.num;

    //다음 갈 곳
    snail nxt;
    nxt.x = cur.x + di[cur.dir];
    nxt.y = cur.y + dj[cur.dir];
    nxt.dir = cur.dir;
    nxt.num = cur.num + 1;

    //다음 갈 곳이 범위를 넘었거나 이미 숫자가 채워져있는 경우, 다음 방향으로 전환
    if (nxt.x <= 0 || nxt.y <= 0 || nxt.x > N || nxt.y > N || map[nxt.x][nxt.y] > 0) {
        nxt.dir++;
        if (nxt.dir == 4) {
            nxt.dir = 0;
        }

        nxt.x = cur.x + di[nxt.dir];
        nxt.y = cur.y + dj[nxt.dir];
    }

    go(nxt);

    return;
}

int main() {
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; test_case++) {

        cin >> N;

        memset(map, 0, sizeof(map));

        //(1,1)에서 0방향(동)으로 숫자 1로 시작
        //범위를 넘어가는 것과 숫자가 채워진 예외 경우를 한꺼번에 처리하기 위해 1,1부터 시작
        snail start = { 1,1,0,1 };
        go(start);

        cout << "#" << test_case << "\n";
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

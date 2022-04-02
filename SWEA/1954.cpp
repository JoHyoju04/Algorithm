#include <iostream>
#include <cstring>
using namespace std;

struct snail {
    //��ǥ
    int x, y;
    //����
    int dir;
    //����
    int num;
};

//��,��,��,��
int di[] = { 0,1,0,-1 };
int dj[] = { 1,0,-1,0 };

int N;
int map[12][12];

void go(snail cur) {

    //�������� : ���ڸ� �� ä���� ���
    if (cur.num > N* N) {
        return;
    }

    map[cur.x][cur.y] = cur.num;

    //���� �� ��
    snail nxt;
    nxt.x = cur.x + di[cur.dir];
    nxt.y = cur.y + dj[cur.dir];
    nxt.dir = cur.dir;
    nxt.num = cur.num + 1;

    //���� �� ���� ������ �Ѿ��ų� �̹� ���ڰ� ä�����ִ� ���, ���� �������� ��ȯ
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

        //(1,1)���� 0����(��)���� ���� 1�� ����
        //������ �Ѿ�� �Ͱ� ���ڰ� ä���� ���� ��츦 �Ѳ����� ó���ϱ� ���� 1,1���� ����
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

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n, m, ans = 100;
int a[8][8], b[8][8];
// dx,dy ������ idx�� 0�� �ð���� ������ �ʱ�ȭ
const int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
struct cctv {
    int n, x, y;
    // ����, ��ġ (x,y)
};
vector<cctv> v; // cctv ����, ��ġ ����
vector<int> dir; // cctv ���� ����
void check(int x, int y, int d) {
    int i = x, j = y;
    while (0 <= i && i < n && 0 <= j && j < m) {
        //������ ����� ������
        if (a[i][j] == 6) break; //���̸� break
        b[i][j] = a[x][y];
        i += dx[d];
        j += dy[d];
    }
}
void solve(int now) {
    if (now == (int)v.size()) {
        //��� CCTV ���� �������� ��
        memcpy(b, a, sizeof(a)); //�ӽù迭 b ���
        for (int i = 0; i < v.size(); i++) {
            if (v[i].n == 1) {
                check(v[i].x, v[i].y, dir[i]);
            }
            else if (v[i].n == 2) {
                check(v[i].x, v[i].y, dir[i]);
                check(v[i].x, v[i].y, (dir[i] + 2) % 4);
            }
            else if (v[i].n == 3) {
                check(v[i].x, v[i].y, dir[i]);
                check(v[i].x, v[i].y, (dir[i] + 1) % 4);
            }
            else if (v[i].n == 4) {
                check(v[i].x, v[i].y, dir[i]);
                check(v[i].x, v[i].y, (dir[i] + 1) % 4);
                check(v[i].x, v[i].y, (dir[i] + 2) % 4);
            }
            else if (v[i].n == 5) {
                check(v[i].x, v[i].y, dir[i]);
                check(v[i].x, v[i].y, (dir[i] + 1) % 4);
                check(v[i].x, v[i].y, (dir[i] + 2) % 4);
                check(v[i].x, v[i].y, (dir[i] + 3) % 4);
            }
        }
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 0) tmp++;
            }
        }
        if (tmp < ans) ans = tmp;
        return;
    }
    for (int i = 0; i < 4; i++) {
        dir[now] = i;
        solve(now + 1);
    }

}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] >= 1 && a[i][j] <= 5) {
                //CCTV ������ ,��ġ (x,y) ����
                v.push_back({ a[i][j],i,j });
                dir.push_back(0);
            }
        }
    }
    solve(0);
    printf("%d\n", ans);
    return 0;
}
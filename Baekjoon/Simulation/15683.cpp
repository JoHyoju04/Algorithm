#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n, m, ans = 100;
int a[8][8], b[8][8];
// dx,dy 동쪽의 idx가 0인 시계방향 순서로 초기화
const int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
struct cctv {
    int n, x, y;
    // 종류, 위치 (x,y)
};
vector<cctv> v; // cctv 종류, 위치 벡터
vector<int> dir; // cctv 방향 벡터
void check(int x, int y, int d) {
    int i = x, j = y;
    while (0 <= i && i < n && 0 <= j && j < m) {
        //범위를 벗어나기 전까지
        if (a[i][j] == 6) break; //벽이면 break
        b[i][j] = a[x][y];
        i += dx[d];
        j += dy[d];
    }
}
void solve(int now) {
    if (now == (int)v.size()) {
        //모든 CCTV 방향 설정했을 떄
        memcpy(b, a, sizeof(a)); //임시배열 b 사용
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
                //CCTV 종류랑 ,위치 (x,y) 저장
                v.push_back({ a[i][j],i,j });
                dir.push_back(0);
            }
        }
    }
    solve(0);
    printf("%d\n", ans);
    return 0;
}
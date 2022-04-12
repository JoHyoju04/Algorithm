#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Group {
    int r, c, cnt, d;
};
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool cmp(Group a, Group b) {
    if (a.r == b.r) return a.c < b.c;
    else return a.r < b.r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {

        int N, M, K, answer = 0;
        vector<Group> g;
        cin >> N >> M >> K;
        for (int i = 0; i < K; i++) {
            int r, c, cnt, d;
            cin >> r >> c >> cnt >> d;
            if (d == 1)    d = 3;
            else if (d == 2)   d = 1;
            else if (d == 3)   d = 2;
            else d = 0;
            g.push_back({ r,c,cnt,d });
        }

        while (M--) {
            for (int i = 0; i < g.size(); i++) {
                if (g[i].cnt == 0) continue;
                int nr = g[i].r + dir[g[i].d][0];
                int nc = g[i].c + dir[g[i].d][1];
                if (nr == 0 || nr == N - 1 || nc == 0 || nc == N - 1) {
                    g[i].cnt /= 2;
                    g[i].d = (g[i].d + 2) % 4;
                }
                g[i].r = nr;
                g[i].c = nc;
            }
            sort(g.begin(), g.end(), cmp);
            int sum = 0, maxCnt = 0, maxI = 0, idx = 0;
            for (int i = 1; i < g.size(); i++) {
                if (g[idx].r == g[i].r && g[idx].c == g[i].c) {
                    sum += g[i].cnt;
                    if (g[i].cnt > maxCnt) {
                        maxCnt = g[i].cnt;
                        maxI = i;
                    }
                    g[i].cnt = 0;
                }
                if (i == g.size() - 1 || !(g[idx].r == g[i].r && g[idx].c == g[i].c)) {
                    if (sum != 0) {
                        sum += g[idx].cnt;
                        if (g[idx].cnt > maxCnt) {
                            maxCnt = g[idx].cnt;
                            maxI = idx;
                        }
                        g[idx].cnt = 0;
                        g[maxI].cnt = sum;
                        sum = 0;
                        maxCnt = 0;
                        maxI = 0;
                    }
                    idx = i;
                }
            }
        }
        for (int i = 0; i < g.size(); i++) {

            answer += g[i].cnt;
        }


        cout << "#" << test_case << " " << answer << '\n';
        g.clear();
    }
    return 0;
}

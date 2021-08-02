#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct info
{
    int r, c, cnt, get;
};
int n, m, t, map[100][100], visited[100][100][2], answer;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void bfs(int r, int c, int cnt, int get)
{
    queue<info>q;
    q.push({ r,c,cnt,get });
    visited[r][c][get] = 1;
    while (!q.empty())
    {
        r = q.front().r;
        c = q.front().c;
        get = q.front().get;
        cnt = q.front().cnt;

        q.pop();
        //검을먹으면 get을 1로바꿔줌
        if (map[r][c] == 2)get = 1;
        //도착하면 탈출하기
        //탈출해야 최단거리를 알수있음
        if (r == n - 1 && c == m - 1)
        {
            answer = cnt;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m)    continue;
            //검 얻었을 때
            if (get == 1)
            {
                if (visited[nr][nc][get] == 0)
                {
                    visited[nr][nc][get] = cnt + 1;
                    q.push({ nr,nc,visited[nr][nc][get],get });
                }
            }
            //검 못먹었을 때
            else
            {
                if (visited[nr][nc][get] == 0 && map[nr][nc] != 1)
                {
                    visited[nr][nc][get] = cnt + 1;
                    q.push({ nr,nc,visited[nr][nc][get],get });
                }
            }
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    //y좌표,x좌표,걸린시간,검획득여부
    bfs(0, 0, 0, 0);
    if (answer >= 1 && answer <= t) cout << answer << '\n';
    else cout << "Fail" << '\n';
}
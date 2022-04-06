#include<iostream>
using namespace std;

int M, N, answer;
int map[501][501];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int dp[501][501];

int dfs(int r, int c)
{
    if (r == M - 1 && c == N - 1) return 1;
    if (dp[r][c] != -1) return dp[r][c];

    dp[r][c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr >= 0 && nc >= 0 && nr < M && nc < N)
        {
            if (map[nr][nc] < map[r][c])
            {
                dp[r][c] = dp[r][c] + dfs(nr, nc);
            }
        }
    }
    return dp[r][c];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }

    answer = dfs(0, 0);

    cout << answer;

    return 0;
}

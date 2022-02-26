#include <iostream>

using namespace std;

int di[9] = { -1, 0, 0, -2, -1, -1, 0, 0, 0 };
int dj[9] = { 0, -1, 0, 0, -1, 0, -2, -1, 0 };
int dk[9] = { 0, 0, -1, 0, 0, -1, 0, -1, -2 };

int A[3001] = { 0, };
int B[101] = { 0, };
int dp[3001][101][101] = { 0, };

int radixArr[10][100];
int radixCnt[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    register int tc, i, j, k, l;
    int T, N, M;
    register int max, tmp, ni, nj, nk;

    cin >> T;
    for (tc = 1; tc <= T; ++tc)
    {
        cin >> N;
        for (i = 1; i <= N; ++i)
            cin >> A[i];
        cin >> M;
        for (i = 1; i <= M; ++i)
            cin >> B[i];

        for (i = 1; i <= 100000; i *= 10)
        {
            fill(radixCnt, radixCnt + 10, 0);
            for (j = 1; j <= M; ++j)
            {
                int radix = ((B[j] / i) % 10);
                radixArr[radix][radixCnt[radix]++] = B[j];
            }

            j = 1;
            for (k = 0; k < 10; ++k)
                for (l = 0; l < radixCnt[k]; ++l)
                    B[j++] = radixArr[k][l];
        }

        for (i = 0; i <= N; ++i)
            for (j = 0; j <= M; ++j)
                for (k = 0; k <= M - j; ++k)
                {
                    if (i + j + k == 0)
                        dp[i][j][k] = 0;
                    else if (i + j + k == 1)
                    {
                        if (i == 1)
                            dp[i][j][k] = A[i];
                        else if (j == 1)
                            dp[i][j][k] = B[M + 1 - j];
                        else
                            dp[i][j][k] = B[k];
                    }
                    else
                    {
                        max = 0;
                        for (l = 0; l < 9; ++l)
                        {
                            ni = i + di[l];
                            nj = j + dj[l];
                            nk = k + dk[l];
                            if (ni >= 0 && nj >= 0 && nk >= 0)
                            {
                                tmp = 0;
                                if (l >= 3)
                                {
                                    if (di[l] < 0)
                                        tmp = A[i];
                                    if (dj[l] < 0)
                                        tmp = (tmp < B[M + 1 - j] ? B[M + 1 - j] : tmp);
                                    if (dk[l] < 0)
                                        tmp = (tmp < B[k] ? B[k] : tmp);
                                }

                                max = (max < dp[ni][nj][nk] + tmp ? dp[ni][nj][nk] + tmp : max);
                            }
                        }
                        dp[i][j][k] = max;
                    }
                }

        int ans = 0;
        for (i = 0; i <= M; ++i)
            ans = (ans < dp[N][i][M - i] ? dp[N][i][M - i] : ans);

        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int v[101][1001];
        int w[101];
        int c[101];
        int N, W, answer = 0;
        cin >> N >> W;

        for (int i = 1; i <= N; i++)
            cin >> w[i] >> c[i];

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                if (w[i] > j)
                    v[i][j] = v[i - 1][j];
                else
                    v[i][j] = c[i] + v[i - 1][j - w[i]] > v[i - 1][j] ? c[i] + v[i - 1][j - w[i]] : v[i - 1][j];
            }
        }
        cout << "#" << tc << " " << v[N][W] << endl;
    }
    return 0;
}
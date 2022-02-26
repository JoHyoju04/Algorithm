#include<iostream>

using namespace std;

int days[200000];
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T, N, M;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            cin >> days[i];

        int start = 0, end = 0;
        int cost = 0, score = 1;
        int ans = 0;
        while (start < N && end < N)
        {
            score = days[end] - days[start] + 1;
            cost = score - (end - start + 1);
            score += M - cost;

            if (score > ans)
                ans = score;

            if (end < N - 1 && days[end + 1] - days[end] - 1 <= M - cost)
                end++;
            else
            {
                start++;
                if (start > end)
                    end = start;
            }
        }
        cout << '#' << test_case << ' ' << ans << '\n';
    }
    return 0;
}
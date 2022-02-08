#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int TC;

    int s[100000];
    int e[100000];

    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int L, N;

        cin >> L >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> s[i] >> e[i];
        }

        int ans = 0;

        int res = 0; // ������
        int target = 0; // ������ ��ġ

        for (int i = 0; i < N && ans != L; i++) // 1.0e5 = 10^5 = 100000 = 100,000 = �鸸
        {
            int pos = s[i]; // ������

            int temp = 0;

            for (; target < N; target++) // 1.0e5 = 10^5 = 100000 = 100,000 = �鸸
            {
                if (e[target] <= pos + L) // ���� ����, ���� �Ϸ�
                {
                    res += e[target] - s[target];

                    continue;
                }

                if (s[target] < pos + L) // �κ� ����, ���� ����
                {
                    temp += pos + L - s[target];
                }

                break;
            }

            ans = max(ans, res + temp);

            if (target > i)
                res -= e[i] - s[i];
            else // target == i
                target++;
        }

        cout << "#" << tc << " " << ans << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
        string a, b, ans = "";
        vector<vector<int>> v(1001, vector<int>(1001, 0));
        cin >> a >> b;

        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                if (a[i - 1] == b[j - 1])
                    v[i][j] = v[i - 1][j - 1] + 1;
                else
                    v[i][j] = max(v[i - 1][j], v[i][j - 1]);
            }
        }
        cout << "#" << tc << " " << v[a.size()][b.size()] << endl;
    }
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int taste[11][2];
int n, answer = 987654321;

void dfs(int idx, int sour, int bitter) {
    if (idx != 0) {
        int sub = abs(sour - bitter);
        answer = min(sub, answer);
    }
    for (int i = idx; i < n; i++) {
        dfs(i + 1, sour * taste[i][0] , bitter + taste[i][1]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> taste[i][0] >> taste[i][1];
    }
    dfs(0, 1, 0);
    cout << answer;
    return 0;
}
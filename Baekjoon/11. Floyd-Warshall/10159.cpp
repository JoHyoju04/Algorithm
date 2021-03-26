#include <iostream>
#include<vector>
using namespace std;
int things[102][102];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        things[a][b] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (things[i][k] && things[k][j])  things[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!things[i][j] && !things[j][i])  cnt++;
        }
        cout << cnt - 1 << "\n";
    }
    return 0;
}
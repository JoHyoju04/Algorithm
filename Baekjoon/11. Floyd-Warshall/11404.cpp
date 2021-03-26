#include <iostream>
#include<vector>
#define MAX 987654321
using namespace std;
vector<vector<int> > city;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    city.assign(n + 1, vector<int>(n + 1, MAX));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (city[a][b] > c)
            city[a][b] = c;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j)    city[i][j] = 0;
                else if (city[i][k] + city[k][j] < city[i][j])  city[i][j] = city[i][k] + city[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == MAX)  cout << "0 ";
            else cout << city[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
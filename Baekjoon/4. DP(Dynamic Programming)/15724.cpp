#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1024 + 1;
int N, M;
int region[MAX][MAX];
int cache[MAX][MAX];

int main(){

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> N >> M;

        for (int x = 1; x <= N; x++)
                 for (int y = 1; y <= M; y++)
                 {
                         cin >> region[x][y];
                         cache[x][y] = region[x][y] + (cache[x - 1][y] + cache[x][y - 1] - cache[x - 1][y - 1]);
                 }
        int K;
        cin >> K;

        for (int i = 0; i < K; i++)
        {
                 int x1, x2, y1, y2;
                 cin >> x1 >> y1 >> x2 >> y2;
                 cout << cache[x2][y2] - (cache[x1 - 1][y2] + cache[x2][y1 - 1] - cache[x1 - 1][y1 - 1]) << "\n";
        }
        return 0;
}
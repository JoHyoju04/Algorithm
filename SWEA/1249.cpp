#include<iostream>
#include<queue>
using namespace std;
int map[101][101];
bool visited[101][101];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int dijktra(int size) {
    priority_queue<pair<pair<int, int>, int > > pq;
    pq.push({ {0,0},0 });
    visited[0][0] = 1;
    while (!pq.empty()) {
        int curTime = -pq.top().first.first;
        int curRow = -pq.top().first.second;
        int curCol = pq.top().second;
        pq.pop();
        if (curRow == size - 1 && curCol == size - 1)	return curTime;

        for (int i = 0; i < 4; i++) {
            int nR = curRow + dir[i][0];
            int nC = curCol + dir[i][1];
            if (nR < 0 || nC < 0 || nR >= size || nC >= size || visited[nR][nC]) continue;
            pq.push({ {-(curTime + map[nR][nC]),-nR },nC });
            visited[nR][nC] = 1;
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            for (int j = 0; j < N; j++) {
                map[i][j] = input[j] - '0';
            }
        }
        int answer = dijktra(N);
        cout << "#" << test_case << " " << answer << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = 0;
                visited[i][j] = 0;
            }
        }
    }
    return 0;
}
#include<iostream>
#include <string>
#include <queue>
using namespace std;

char map[301][301];
bool visited[301][301];
int dir[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1} };
int N;
int answer;
bool check(int x, int y)
{
    for (int i = 0; i < 8; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (0 <= nx && nx < N && 0 <= ny && ny < N) {
            if (map[nx][ny] == '*') {
                return false;
            }
        }
    }
    return true;
}

void play()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j] && map[i][j] == '.' && check(i, j)) {
                answer++;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    visited[x][y] = 1;
                    q.pop();

                    for (int k = 0; k < 8; k++) {
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] && map[nx][ny] == '.') {
                            visited[nx][ny] = 1;
                            if (check(nx, ny)) {
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        answer = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            string input;
            cin >> input;
            for (int j = 0; j < N; j++) {
                map[i][j] = input[j];
            }
        }
        play();
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (!visited[j][k] && map[j][k] == '.') {
                    answer++;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = '.';
                visited[i][j] = 0;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";


    }
    return 0;
}
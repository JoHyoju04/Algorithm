#include<iostream>
#include<vector>
using namespace std;

int dir[8][2] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int bucket[51][51];
int N, M;
vector<pair<int, int> > rain;
bool visited[51][51];

void move(int d, int s) {
    for (int i = 0; i < rain.size(); i++) {
        int nextR = rain[i].first;
        int nextC = rain[i].second;

        for (int j = 0; j < s; j++) {
            nextR = nextR + dir[d - 1][0];
            nextC = nextC + dir[d - 1][1];
            if (nextR >= N)    nextR = 0;
            if (nextC >= N)    nextC = 0;
            if (nextR < 0) nextR = N - 1;
            if (nextC < 0) nextC = N - 1;
        }
        bucket[nextR][nextC] += 1;
        visited[nextR][nextC] = 1;
    }
    rain.clear();
}

void magic() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (visited[i][j] == 1) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nextR = i + dir[k * 2 + 1][0];
                    int nextC = j + dir[k * 2 + 1][1];
                    if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N || bucket[nextR][nextC] <= 0)   continue;
                    cnt++;
                }
                bucket[i][j] += cnt;
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> bucket[i][j];
            if (i == N - 1 || i == N - 2) {
                if (j == 0 || j == 1)  rain.push_back({ i,j });
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;

        move(d, s);

        magic();

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (bucket[j][k] >= 2 && !visited[j][k]) {
                    rain.push_back({ j,k });
                    bucket[j][k] -= 2;
                }
                visited[j][k] = 0;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer += bucket[i][j];
        }
    }

    cout << answer;

    return 0;
}
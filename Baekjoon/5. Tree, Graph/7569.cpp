#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100;

struct Dir
{
    int y, x, z;
};

Dir moveDir[6] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
int M, N, H;
int tomato[MAX][MAX][MAX];
queue<pair<pair<int, int>, int>> q;
int noTomato;

bool allRipe()
{
    int possible = M * N * H - noTomato;

    int cnt = 0;

    for (int i = 0; i < H; i++)

        for (int j = 0; j < N; j++)

            for (int k = 0; k < M; k++)

                if (tomato[j][k][i] == 1)

                    cnt++;

    return possible == cnt;
}


int BFS()
{
    int day = 0;

    if (q.empty())        return -1;

    while (!q.empty())
    {
        int currentSize = q.size();

        for (int i = 0; i < currentSize; i++)
        {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int z = q.front().second;

            for (int i = 0; i < 6; i++)
            {

                int nextY = y + moveDir[i].y;
                int nextX = x + moveDir[i].x;
                int nextZ = z + moveDir[i].z;

                if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M && 0 <= nextZ && nextZ < H)

                    if (tomato[nextY][nextX][nextZ] == 0)
                    {
                        tomato[nextY][nextX][nextZ] = 1;

                        q.push(make_pair(make_pair(nextY, nextX), nextZ));

                    }

            }

            q.pop();

            if (q.size() == 0 && allRipe()) return day;
            else if (q.size() == 0 && !allRipe())   return -1;

        }
        day++;

    }

}

int main()
{
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)

        for (int j = 0; j < N; j++)

            for (int k = 0; k < M; k++)

            {

                cin >> tomato[j][k][i];

                if (tomato[j][k][i] == 1)

                    q.push(make_pair(make_pair(j, k), i));

                if (tomato[j][k][i] == -1)

                    noTomato++;

            }
    if (q.size() == M * N * H - noTomato)
    {
        cout << 0 << endl;
    }
    else
    {
        int result = BFS();
        cout << result << endl;
    }

    return 0;
}
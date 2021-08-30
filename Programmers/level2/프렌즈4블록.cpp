#include <string>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<vector<bool>> v;
int solution(int m, int n, vector<string> board);
bool check(int ii, int jj, vector<string> board);
vector<string> erase(vector<string> board);

int solution(int m, int n, vector<string> board) {
    M = m;
    N = n;
    int answer = 0;
    bool flag = false;
    while (!flag) {
        v = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 'x') 
                    continue;
                if (check(i, j, board))
                    flag = true;
            }
        }
        if (!flag) break;
        board = erase(board);
        flag = false;
    }

    //answer계산
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'x')
                answer++;
        }
    }

    return answer;
}

//지울 블럭이 있으면 true, 없으면 false 반환
bool check(int ii, int jj, vector<string> board) {
    int iter_x[3] = { 1,1,0 };
    int iter_y[3] = { 0,1,1 };
    char c = board[ii].at(jj);

    for (int i = 0; i < 3; i++) {
        int next_x = jj + iter_x[i];
        int next_y = ii + iter_y[i];
        if (next_x >= N || next_y >= M || 
            c != board[next_y].at(next_x)) {
            return false;
        }
    }

    v[ii][jj] = true;
    for (int i = 0; i < 3; i++) {
        int next_x = jj + iter_x[i];
        int next_y = ii + iter_y[i];
        v[next_y][next_x] = true;
    }
    return true;
}

vector<string> erase(vector<string> board) {
    for (int i = 0; i < N; i++) {
        queue<char> q;
        for (int j = M -1; j >= 0; j--) {
            if (v[j][i]) //지워야할블럭
                continue;
            q.push(board[j][i]);
        }
        for (int j = M - 1; j >= 0; j--) {
            if (q.empty())
                board[j][i] = 'x';
            else {
                board[j][i] = q.front();
                q.pop();
            }
        }
    }
    return board;
}
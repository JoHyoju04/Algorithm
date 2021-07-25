#include <vector>
#include<iostream>
using namespace std;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int R, C, N;
vector<vector<char> > bomb(vector<vector<char> >& vec) {
    vector<vector<char> > ret(R, vector<char>(C, 'O'));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (vec[i][j] == 'O') {
                for (int k = 0; k < 4; k++) {
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if (r >= 0 && r < R && c >= 0 && c < C)    ret[r][c] = '.';
                }
                ret[i][j] = '.';
            }
        }
    }
    return ret;
}

void print(vector<vector<char> >& vec) {
    for (int i = 0; i <R; i++) {
        for (int j = 0; j < C; j++) {
            cout << vec[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<vector<char> > board;
    cin >> R >> C >> N;
    board.assign(R, vector<char>(C,'O'));

    for (int i = 0; i < R; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++) {
            board[i][j] = input[j];
        }
    }
    if (N % 2 == 0) {
        board.assign(R, vector<char>(C, 'O'));
        print(board);
        return 0;
    }
    
    for (int i = N; i > 1; i -= 2) {
        board = bomb(board);
    }
    print(board);
    return 0;
}
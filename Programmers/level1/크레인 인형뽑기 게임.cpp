#include <string>
#include <vector>
#include <stack>
#include<iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, doll;
    stack<int> st;
    for (int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][col] != 0) {
                doll = board[j][col];
                board[j][col] = 0;
                if (st.empty() || st.top() != doll)  st.push(doll);
                else {

                    st.pop();
                    answer += 2;
                }
                break;
            }
        }
    }
    return answer;
}
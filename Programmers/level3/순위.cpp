#include <string>
#include <vector>

using namespace std;
int winList[102][102];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); i++) {
        winList[results[i][0]][results[i][1]] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (winList[i][k] && winList[k][j])    winList[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += winList[i][j] + winList[j][i];
        }
        if (cnt == n - 1)  answer++;
    }
    return answer;
}
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> lion;
int answerSum;
void dfs(int k, int n, vector<int>& answer, vector<int>& info) {
    if (k == 11) {
        int aSum = 0, lSum = 0;
        for (int i = 0; i < 11; i++) {
            if (info[i] == 0 && lion[i] == 0)    continue;
            if (info[i] >= lion[i])    aSum += 10 - i;
            else lSum += 10 - i;
        }

        if (aSum < lSum && answerSum <= (lSum - aSum)) {
            if (answerSum == (lSum - aSum)) {
                for (int i = 10; i >= 0; i--) {
                    if (answer[i] > lion[i])   break;
                    else if (answer[i] < lion[i]) {
                        answer = lion;
                        break;
                    }
                }
            }
            else answer = lion;
            answerSum = lSum - aSum;
        }
        return;
    }
    for (int i = 0; i <= n; i++) {
        lion.push_back(i);
        dfs(k + 1, n - i, answer, info);
        lion.pop_back();
    }
}
vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, -1);
    answerSum = 0;
    dfs(0, n, answer, info);
    if (answer[0] == -1)   answer.assign(1, -1);
    return answer;
}
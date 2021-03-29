#include <string>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer, exArray;
    for (int i = 0; i < commands.size(); i++) {
        exArray.assign(array.begin() + (commands[i][0] - 1), array.begin() + commands[i][1]);
        sort(exArray.begin(), exArray.end());
        answer.push_back(exArray[commands[i][2] - 1]);
    }

    return answer;
}
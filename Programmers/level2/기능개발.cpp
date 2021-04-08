#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int before, cnt = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int remain = (100 - progresses[i]) / speeds[i];
        if ((100 - progresses[i]) % speeds[i] != 0)    remain += 1;

        if (i == 0)    before = remain;

        if (before >= remain)   cnt++;
        else {
            answer.push_back(cnt);
            cnt = 1;
            before = remain;
        }
    }
    answer.push_back(cnt);
    return answer;
}
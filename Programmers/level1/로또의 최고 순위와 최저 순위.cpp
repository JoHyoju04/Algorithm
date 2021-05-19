#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int calculate(int score) {
    if (score == 6)    return 1;
    else if (score == 5)   return 2;
    else if (score == 4)   return 3;
    else if (score == 3)   return 4;
    else if (score == 2)   return 5;
    else return 6;
}
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCnt = 0, sameCnt = 0;

    sort(lottos.begin(), lottos.end());

    if (lower_bound(lottos.begin(), lottos.end(), 1) != lottos.begin())    zeroCnt = lower_bound(lottos.begin(), lottos.end(), 1) - lottos.begin();

    for (int i = 0; i < 6; i++) {
        if (find(lottos.begin(), lottos.end(), win_nums[i]) != lottos.end()) sameCnt++;
    }

    answer.push_back(calculate(zeroCnt + sameCnt));
    answer.push_back(calculate(sameCnt));
    return answer;
}
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = sticker[0];
    int dp1[100002] = { 0, };
    int dp2[100002] = { 0, };
    
    dp1[0] = dp1[1] = sticker[0];
    dp2[0] = 0, dp2[1] = sticker[1];
    
    for(size_t i = 2; i < sticker.size(); i++){
        if(i != sticker.size() - 1) {
            dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
            answer = dp1[i];
        }
        dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);
    }
    answer = max(answer, dp2[sticker.size() - 1]);
    return answer;
}
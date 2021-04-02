#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    for (int i = 0; i < prices.size() - 1; i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] == 1 || j == prices.size() - 1)
                answer[i] = prices.size() - (i + 1);
            else if (prices[j] <= prices[i] - 1) {
                answer[i] = j - i;
                break;
            }
        }
    }
    return answer;
}
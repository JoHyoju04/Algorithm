#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, mix = 0;
    priority_queue<int, vector<int>, greater<int>> sorted;
    for (int i = 0; i < scoville.size(); i++) {
        sorted.push(scoville[i]);
    }
    while (sorted.top() < K) {
        if (sorted.size() == 1)    return -1;
        mix = sorted.top();
        sorted.pop();
        mix += sorted.top() * 2;
        sorted.pop();
        sorted.push(mix);
        answer++;
        mix = 0;
    }
    return answer;
}
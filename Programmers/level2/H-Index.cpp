#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int h, h_cnt, answer = 0;
    sort(citations.begin(), citations.end());
    for (int h = 0; h < *max_element(citations.begin(), citations.end()); h++) {
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= h) {
                h_cnt = citations.size() - j;
                break;
            }
        }
        if (h > h_cnt) break;
        else if (citations.size() - h_cnt <= h && answer < h) answer = h;
    }
    return answer;
}
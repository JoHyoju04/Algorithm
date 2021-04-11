#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int yellow_len = (brown - 4) / 2;
    for (int i = 1; i <= sqrt(yellow); i++) {
        if (yellow % i == 0 && yellow_len == yellow / i + i) {
            answer[0] = yellow / i + 2;
            answer[1] = i + 2;
            break;
        }
    }
    return answer;
}
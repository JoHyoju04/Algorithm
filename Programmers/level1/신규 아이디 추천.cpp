#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string new_id) {
    string answer = new_id;
    bool flag = false;
    for (int i = 0; i < answer.size(); i++) {
        char c = answer[i];
        if (isupper(c))  answer[i] = c + 32;
        if (!(isdigit(c) || c == '.' || c == '-' || c == '_' || islower(c))) {
            answer.erase(answer.begin() + i);
            i--;
            continue;
        }
        if (c == '.') {
            if (flag) {
                answer.erase(answer.begin() + i);
                i--;
                continue;
            }
            else flag = true;
        }
        else flag = false;
    }
    if (answer[0] == '.')  answer.erase(answer.begin());
    if (answer.back() == '.')  answer.pop_back();
    if (answer.size() == 0)    answer += "a";
    if (answer.size() >= 16) {
        if (answer[14] == '.') answer = answer.substr(0, 14);
        else answer = answer.substr(0, 15);
    }
    if (answer.size() <= 2)    answer.insert(answer.size() - 1, 3 - answer.size(), answer.back());
    return answer;
}
#include <string>
#include <vector>

using namespace std;
int answer = 11;
vector<bool> visited(10, 0);
bool isPossible(string str, string target) {
    int diff = 0;
    for (int i = 0; i < target.size(); i++) {
        if (target[i] != str[i])   diff++;
    }
    if (diff == 1) return true;
    else return false;
}
void dfs(string& change, string target, vector<string> words, int cnt) {
    if (change == target) {
        answer = answer < cnt ? answer : cnt;
        return;
    }
    else if (cnt >= 10)    return;
    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && isPossible(words[i], change)) {
            visited[i] = 1;
            dfs(words[i], target, words, cnt + 1);
            visited[i] = 0;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words, 0);
    if (answer == 11)  answer = 0;
    return answer;
}
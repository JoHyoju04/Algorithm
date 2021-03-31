#include <string>
#include <vector>

using namespace std;
bool check(int num, int index, vector<int>& lost, vector<int>& reserve) {
    for (int i = 0; i < reserve.size(); i++) {
        if (num == reserve[i]) {
            lost.erase(lost.begin() + index);
            lost.insert(lost.begin() + index, 0);
            reserve.erase(reserve.begin() + i);
            return true;
        }
    }
    return false;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
                j--;
            }
        }
    }
    for (int a = 0; a < lost.size(); a++) {
        if (lost[a] - 1 == 0 || !check(lost[a] - 1, a, lost, reserve)) {
            if (lost[a] + 1 == n + 1 || !check(lost[a] + 1, a, lost, reserve))
                answer--;
        }
    }
    return answer;
}
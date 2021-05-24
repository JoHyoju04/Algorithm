#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
vector<int> answer;
vector<int> parent;
void DFS(int idx, int money) {
    if (idx == -1) return;
    int m = money * 0.1;
    if (m < 1) {
        answer[idx] += money;
        return;
    }
    else answer[idx] += money - (m);
    DFS(parent[idx], m);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    parent.assign(enroll.size(), 0);
    answer.assign(enroll.size(), 0);
    int idx = 0;
    for (auto s : enroll)  m[s] = idx++;
    for (int i = 0; i < referral.size(); i++) {
        idx = m[enroll[i]];
        if (referral[i] == "-")    parent[idx] = -1;
        else parent[idx] = m[referral[i]];
    }

    for (int i = 0; i < seller.size(); i++) {
        DFS(m[seller[i]], amount[i] * 100);
    }

    return answer;
}
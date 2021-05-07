#include <string>
#include <vector>
#include <stack> 
using namespace std;
bool balance(string s) {
    stack<char> st;
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
            flag = false;
        }
        else if (!st.empty()) st.pop();
    }
    if (!flag && st.empty())   return true;
    return false;
}
string dfs(string w) {
    if (w == "")   return "";
    string u, v;
    int open_cnt = 0, close_cnt = 0;
    for (int i = 0; i < w.size(); i++) {
        if (w[i] == '(') {
            open_cnt++;
        }
        else {
            close_cnt++;
        }
        if (close_cnt == open_cnt) {
            u = w.substr(0, i + 1);
            v = w.substr(i + 1);
            break;
        }
    }
    if (balance(u))   return u + dfs(v);
    else {
        string tmp = u;
        u.clear();
        for (int i = 1; i < tmp.size() - 1; i++) {
            if (tmp[i] == '(')    u += ')';
            else u += '(';
        }
        return '(' + dfs(v) + ')' + u;
    }
}
string solution(string p) {
    string answer = dfs(p);
    return answer;
}
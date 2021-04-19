#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.size() == 1) break;
        char first = s[0];
        s = s.substr(1);
        s += first;
        stack<char> st;
        bool key = false;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '[' || s[j] == '(' || s[j] == '{') {
                st.push(s[j]);
                key = true;
                continue;
            }
            if (!st.empty()) {
                if ((st.top() == '[' && s[j] == ']') || (st.top() == '(' && s[j] == ')') || (st.top() == '{' && s[j] == '}'))   st.pop();
            }
        }
        if (key && st.empty())  answer++;
    }
    return answer;
}
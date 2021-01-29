#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string str;
    stack<char> s;
    int key;
    while (true) {
        getline(cin, str);
        if (str == ".")    break;
        for (int i = 0; i < str.size(); i++) {
            key = 0;
            if (str[i] == '(' || str[i] == '[')   s.push(str[i]);
            else if (str[i] == ')') {
                if (!s.empty() && s.top() == '(') {
                    s.pop();
                }
                else {
                    cout << "no\n";
                    key = 1;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!s.empty() && s.top() == '[') {
                    s.pop();
                }
                else {
                    cout << "no\n";
                    key = 1;
                    break;
                }
            }
        }
        if (key != 1) {
            if (s.empty())   cout << "yes" << endl;
            else
                cout << "no\n";
        }
        while (!s.empty())   s.pop();
    }
    return 0;
}
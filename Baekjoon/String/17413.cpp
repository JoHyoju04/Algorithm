#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str, answer, temp;
    bool key = false;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '<') key = true;
        else if (str[i] == '>')    key = false;

        if (key || str[i] == '>') {
            if (temp.size() != 0) {
                answer += temp;
                temp.clear();
            }
            answer += str[i];
            continue;
        }
        else if (!key) {
            if (str[i] == ' ') {
                temp += " ";
                answer += temp;
                temp.clear();
            }
            else temp.insert(0, 1, str[i]);
        }
    }
    answer += temp;
    cout << answer;
    return 0;
}
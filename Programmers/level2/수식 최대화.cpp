#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

vector<string> pri = { "*-+","*+-","+*-","+-*","-*+","-+*" };

long long calculate(long long a, long long b, char c) {
    switch (c) {
    case '+':return a + b;
    case '-':return a - b;
    case '*':return a * b;
    }
}
long long solution(string expression) {
    vector<long long> nums;
    vector<char> op;
    string str = "";
    long long answer = 0;
    for (int i = 0; i < expression.size(); i++) {
        char c = expression[i];
        if (c == '*' || c == '-' || c == '+') {
            op.push_back(c);
            nums.push_back(stoi(str));
            str = "";
        }
        else str += c;
        if (i == expression.size() - 1)  nums.push_back(stoi(str));
    }

    for (int i = 0; i < 6; i++) {
        vector<long long> copyN(nums.begin(), nums.end());
        vector<char> copyOp = op;
        for (int j = 0; j < 3; j++) {
            char ch = pri[i][j];
            for (int k = 0; k < copyOp.size(); k++) {
                if (copyOp[k] == ch) {
                    long long n = calculate(copyN[k], copyN[k + 1], ch);
                    copyN[k] = n;
                    copyN.erase(copyN.begin() + k + 1);
                    copyOp.erase(copyOp.begin() + k);
                    k--;
                }
            }
        }
        answer = answer > abs(copyN[0]) ? answer : abs(copyN[0]);
    }

    return answer;
}
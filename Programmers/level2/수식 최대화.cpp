#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

long long solution(string expression) {
    vector<long long> ori_num;
    vector<char>ori_op;
    vector<string>pri = { "*-+","*+-","+*-","+-*","-*+","-+*" };
    string n = "";
    long long answer = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
            ori_op.push_back(expression[i]);
            ori_num.push_back(stoll(n));
            n = "";
        }
        else n += expression[i];
    }
    ori_num.push_back(stoll(n));
    for (int j = 0; j < 6; j++) {
        vector<long long> num = ori_num;
        vector<char> op = ori_op;
        for (int k = 0; k < 3; k++) {
            for (int idx = 0; idx < op.size(); idx++) {
                if (op[idx] == pri[j][k]) {
                    if (op[idx] == '*')    num[idx] = num[idx] * num[idx + 1];
                    else if (op[idx] == '-')   num[idx] = num[idx] - num[idx + 1];
                    else if (op[idx] == '+')   num[idx] = num[idx] + num[idx + 1];
                    num.erase(num.begin() + idx + 1);
                    op.erase(op.begin() + idx);
                    idx--;
                }
            }
        }
        answer = answer < abs(num[0]) ? abs(num[0]) : answer;
    }
    return answer;
}
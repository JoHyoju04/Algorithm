#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdlib>
#include <string>
#define MAX 1000000000
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while (true) {
        string order, X;
        vector<string> oper;
        int num, N;

        while (true) {
            getline(cin, order);
            if (order == "QUIT") return 0;
            if (order == "END")    break;

            oper.push_back(order);
        }

        cin >> N;
        for (int i = 0; i < N; i++) {
            stack<int> st;
            long long result = 0;
            bool isError = false;
            cin >> num;
            st.push(num);

            for (int j = 0; j < oper.size(); j++) {
                string str = oper[j];
                long long first, second;
                if (isError) break;

                if (str.substr(0, 3) == "NUM") {
                    st.push(stoi(str.substr(4, str.size() - 4)));
                }
                else if (st.empty()) {
                    isError = true;
                    break;
                }
                else if (str == "POP") {
                    st.pop();
                }
                else if (str == "INV") {
                    first = st.top();
                    st.pop();
                    st.push(first * (-1));
                }
                else if (str == "DUP") {
                    first = st.top();
                    st.push(first);
                }
                else if (str == "SWP") {
                    if (st.size() < 2) {
                        isError = true;
                        break;
                    }
                    first = st.top();
                    st.pop();
                    second = st.top();
                    st.pop();
                    st.push(first);
                    st.push(second);
                }
                else if (str == "ADD") {
                    if (st.size() < 2) {
                        isError = true;
                        break;
                    }
                    first = st.top();
                    st.pop();
                    second = st.top();
                    st.pop();
                    result = first + second;

                    if (abs(result) > MAX) {
                        isError = true;
                    }
                    else st.push((int)first + (int)second);

                }
                else if (str == "SUB") {
                    if (st.size() < 2) {
                        isError = true;
                        break;
                    }
                    first = st.top();
                    st.pop();
                    second = st.top();
                    st.pop();
                    result = second - first;

                    if (abs(result) > MAX) {
                        isError = true;
                    }
                    else st.push((int)second - (int)first);

                }
                else if (str == "MUL") {
                    if (st.size() < 2) {
                        isError = true;
                        break;
                    }
                    first = st.top();
                    st.pop();
                    second = st.top();
                    st.pop();
                    result = second * first;

                    if (abs(result) > MAX) {
                        isError = true;
                        break;
                    }
                    else st.push((int)second * (int)first);

                }
                else if (str == "DIV") {
                    if (st.size() < 2) isError = true;
                    else
                    {
                        first = st.top();
                        st.pop();
                        second = st.top();
                        st.pop();
                        if (first == 0) isError = true;
                        else
                        {
                            int minusCnt = (first < 0) + (second < 0);
                            st.push(abs(second) / abs(first) * (minusCnt == 1 ? -1 : 1));
                        }
                    }

                }
                else if (str == "MOD") {
                    if (st.size() < 2) isError = true;
                    else
                    {
                        first = st.top();
                        st.pop();
                        second = st.top();
                        st.pop();
                        if (first == 0) isError = true;
                        else st.push(second % first);
                    }
                }

            }
            if (isError || st.size() != 1) cout << "ERROR\n";
            else cout << st.top() << "\n";
        }
        cout << "\n";

    }
    return 0;
}
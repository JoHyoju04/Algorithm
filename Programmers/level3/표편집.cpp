#include <string>
#include <vector>
#include <stack>
using namespace std;

int cur;
stack<int> st;

// ���� ����Ʈ node
struct Node {
    int num;
    Node* prev;
    Node* next;
    Node(int num) :num(num), prev(NULL), next(NULL) {};
};

vector<Node*> v;

void solve(vector<string>& cmd) {
    for (string s : cmd) {
        if (s[0] == 'D' || s[0] == 'U') {
            int x = stoi(s.substr(2));
            if (s[0] == 'D') while (x--) cur = v[cur]->next->num;
            else while (x--) cur = v[cur]->prev->num;
        }
        else if (s[0] == 'C') {
            st.push(cur);
            if (v[cur]->prev != NULL)
                v[cur]->prev->next = v[cur]->next;
            if (v[cur]->next != NULL) {
                v[cur]->next->prev = v[cur]->prev;
                cur = v[cur]->next->num;
            }
            else cur = v[cur]->prev->num;
        }
        else if (s[0] == 'Z') {
            int r = st.top(); st.pop();
            if (v[r]->prev != NULL)
                v[r]->prev->next = v[r];
            if (v[r]->next != NULL)
                v[r]->next->prev = v[r];
        }
        else return; //oops
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');

    // ���Ḯ��Ʈ ���� �� ����
    v = vector<Node*>(n);

    for (int i = 0; i < n; i++)
        v[i] = new Node(i);

    v[0]->next = v[1];
    v[n - 1]->prev = v[n - 2];

    for (int i = 1; i < n - 1; i++) {
        v[i]->next = v[i + 1];
        v[i]->prev = v[i - 1];
    }

    // cmd ����
    cur = k;
    solve(cmd);

    // ���� ���� üũ
    int leftCheck, rightCheck;
    leftCheck = rightCheck = cur;

    answer[cur] = 'O';

    // ���� Ŀ�� ���� ���� üũ
    while (v[leftCheck]->prev != NULL) {
        leftCheck = v[leftCheck]->prev->num;
        answer[leftCheck] = 'O';
    }

    // ���� Ŀ�� ���� ������ üũ
    while (v[rightCheck]->next != NULL) {
        rightCheck = v[rightCheck]->next->num;
        answer[rightCheck] = 'O';
    }

    return answer;
}
/*   ��Ȯ��: 30.0   ,   ȿ����: 0.0
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    map<int, int> m;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        m.insert({ i,i });
        answer += 'X';
    }

    auto iter = m.begin();
    for (int i = 0; i < k; i++)    iter++;

    for (int i = 0; i < cmd.size(); i++) {
        string str = cmd[i];
        if (str[0] == 'D') {
            string x = str.substr(2);
            for (int j = 0; j < stoi(x); j++)
                iter++;
        }
        else if (str[0] == 'U') {
            string x = str.substr(2);
            for (int j = 0; j < stoi(x); j++)
                iter--;
        }
        else if (str[0] == 'C') {
            st.push(iter->first);

            iter = m.erase(iter);

            if (iter == m.end())   iter--;
        }
        else {
            m.insert({ st.top(),st.top() });
            st.pop();
        }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        int idx = it->first;
        answer[idx] = 'O';
    }
    return answer;
}
*/
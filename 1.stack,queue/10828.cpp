#include <iostream>
using namespace std;
int front = -1;
int st[100001] = { 0, };
bool empty() {
    if (front == -1)   return true;
    else return false;
}
int top() {
    if (empty()) return -1;
    else
        return st[front];
}
int pop() {
    if (empty()) return -1;
    else {
        int n = st[front];
        st[front--] = 0;
        return n;
    }
}
int main() {
    int N;
    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> str;
        if (str == "push") {
            cin >> n;
            st[++front] = n;
        }
        else if (str == "top")
            cout << top() << "\n";
        else if (str == "size")
            cout << front + 1 << "\n";
        else if (str == "pop")
            cout << pop() << "\n";
        else if (str == "empty")
            cout << empty() << "\n";
    }
    return 0;
}
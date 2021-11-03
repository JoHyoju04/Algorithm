#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, x, rear = -1, front = -1;
    string order = "";

    cin >> N;
    q.assign(N+1,0);
    while (N--) {
        cin >> order;
        if (order == "push") {
            cin >> x;
            q[++rear] = x;
        }
        else if (order == "pop") {
            if (rear == front) cout << "-1" << "\n";
            else cout << q[++front] << "\n";
        }
        else if (order == "size") {
            cout << rear - front<<"\n";
        }
        else if (order == "empty") {
            if (rear == front) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else if (order == "front") {
            if (rear == front) cout << "-1" << "\n";
            else cout << q[front + 1] << "\n";
        }
        else {
            if (rear == front) cout << "-1" << "\n";
            else cout << q[rear] << "\n";
        }
    }
    return 0;
}
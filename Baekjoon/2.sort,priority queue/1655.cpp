#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<> > bigger;

    int mid;
    cin >> mid;
    cout << mid << "\n";

    for (int i = 1; i < N; i++) {
        int n;
        cin >> n;

        if (i % 2 == 0) {
            if (mid < n) {
                bigger.push(n);
                smaller.push(mid);
                mid = bigger.top();
                bigger.pop();
            }
            else smaller.push(n);
        }
        else {
            if (mid > n) {
                smaller.push(n);
                bigger.push(mid);
                mid = smaller.top();
                smaller.pop();
            }
            else bigger.push(n);
        }
        cout << mid << "\n";
    }

}
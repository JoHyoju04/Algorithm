#include <iostream>
using namespace std;
int main() {
    int T, n;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            cin >> n;
            if (n % 2 == 1) sum += n;
        }
        cout << "#" << tc << " " << sum << endl;
    }
}
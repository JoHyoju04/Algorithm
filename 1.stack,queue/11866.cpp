#include <iostream>
using namespace std;

int main() {
    int N, K, arr[1001] = { 0, }, count = 0, index = 0;
    cin >> N >> K;
    cout << "<";
    for (int i = 0; i < N; i++) {
        while (count != K) {
            index++;
            if (index == N + 1)  index = 1;
            if (arr[index] != -1)  ++count;
        }
        count = 0;
        arr[index] = -1;
        cout << index;
        if (i != N - 1)  cout << ", ";
        else cout << ">";
    }
    return 0;
}
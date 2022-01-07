#include<iostream>
using namespace std;

int fib(int n, int k) {
    if (n == k || k == 0)    return 1;
    return fib(n - 1, k - 1) + fib(n - 1, k);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K, answer = 0;
    cin >> N >> K;

    answer = fib(N, K);

    cout << answer;

    return 0;
}
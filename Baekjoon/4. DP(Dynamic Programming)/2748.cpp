#include <iostream>
#include <vector>
using namespace std;

long long fib(int n) {
    vector<long long> f;
    f.assign(n + 1, 0);
    f[1] = 1;

    if (n == 1 || n == 0)   return f[n];

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    long long answer;

    cin >> n;

    answer = fib(n);

    cout << answer;

    return 0;

}
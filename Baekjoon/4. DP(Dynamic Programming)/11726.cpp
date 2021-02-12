#include<iostream>
using namespace std;
long long tile[1001];
void tilling(int n) {
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == 2)  tile[i] = i;
        else tile[i] = (tile[i - 1] % 10007 + tile[i - 2] % 10007) % 10007;
    }
}
int main()
{
    int n;
    cin >> n;
    tilling(n);
    cout << tile[n];
    return 0;
}
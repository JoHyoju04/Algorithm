#include<iostream>
using namespace std;

bool cnt[10002];

int d(int n) {

    int ret = n;
    while (n) {
        ret += (n % 10);
        n /= 10;
    }
    return ret;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tmp;
    for (int i = 1; i <= 10000; i++) {
        tmp = d(i);
        if (tmp <= 10000)    cnt[tmp] = 1;
    }

    for (int i = 1; i <= 10000; i++) {
        if (!cnt[i])    cout << i << "\n";
    }

    return 0;
}
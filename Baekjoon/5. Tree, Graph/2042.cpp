#include <iostream>
using namespace std;

#define MAXK 21
int N, M, K, B, T;
long long IDT[1 << MAXK];

void init() {
    for (int i = B - 1; i > 0; i--)
        IDT[i] = IDT[i * 2] + IDT[i * 2 + 1];
}

void update(int idx, long long value) {
    idx += B - 1;
    IDT[idx] = value;
    while (idx >>= 1) {
        IDT[idx] = IDT[idx * 2] + IDT[idx * 2 + 1];
    }
}

long long lgSum(int l, int r) {
    l += B - 1;
    r += B - 1;
    long long sum = 0;
    while (l <= r) {
        if ((l & 1) == 1)    sum += IDT[l];
        if ((r & 1) == 0)    sum += IDT[r];

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (B = 1; B < N; B <<= 1);
    for (int i = B; i < B + N; i++)  cin >> IDT[i];

    init();

    T = M + K;
    int a, b;
    long long c;

    while (T--) {
        cin >> a >> b >> c;
        if (a == 1)    update(b, c);
        else cout << lgSum(b, c) << "\n";
    }

    return 0;

}
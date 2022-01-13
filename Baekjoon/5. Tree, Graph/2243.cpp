#include <iostream>
using namespace std;

#define MAX 1000000
#define MAXK 21

int n, B;
long long IDT[1 << MAXK];

int search(int k)
{
    int p = 1;
    while (p < B)
    {
        p <<= 1;

        if (IDT[p] < k)
        {
            k -= IDT[p];
            p += 1;
        }
    }

    return p - (B - 1);
}

void update(int idx, int value) {
    idx += B - 1;
    IDT[idx] += value;
    while (idx >>= 1) {
        IDT[idx] = IDT[idx * 2] + IDT[idx * 2 + 1];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (B = 1; B < MAX; B <<= 1);

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        if (a == 2) {
            cin >> b >> c;
            update(b, c);
        }
        else {
            cin >> b;
            c = search(b);

            cout << c << "\n";
            update(c, -1);
        }
    }

    return 0;

}
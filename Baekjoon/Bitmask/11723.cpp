#include<iostream>
#include<string>
#include<bitset>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int M, x;
    string s;
    bitset <20> bit;
    cin >> M;
    while (M--) {
        cin >> s;
        if (s != "all" && s != "empty")    cin >> x;
        else x = 0;

        if (s == "add")    bit.set(x - 1, true);
        else if (s == "remove")    bit.set(x - 1, false);
        else if (s == "check") cout << bit.test(x - 1)<<'\n';
        else if (s == "toggle") {
            if (bit.test(x - 1))   bit.set(x - 1, false);
            else
            {
                bit.set(x - 1, true);
            }
        }
        else if (s == "all")   bit.set();
        else bit.reset();
    }
    return 0;
}
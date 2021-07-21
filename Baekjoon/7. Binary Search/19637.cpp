#include<iostream>
#include<map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    map<int, string> m;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int value;
        string name;
        cin >> name >> value;
        if (m.find(value) != m.end())
            continue;
        m.insert({ value,name });
    }

    for (int i = 0; i < M; i++) {
        int power;
        cin >> power;
        auto iter = m.lower_bound(power);
        cout << iter->second << "\n";
    }
    return 0;
}

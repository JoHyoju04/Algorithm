#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    map<string, int> list;
    cin >> N >> M;

    for (int i = 0; i < N + M; i++) {
        string name;
        cin >> name;
        list[name]++;
    }

    vector<string> answer;
    for (auto iter = list.begin(); iter != list.end(); iter++) {
        if (iter->second == 2) answer.push_back(iter->first);
    }

    cout << answer.size() << "\n";
    for (string name : answer) cout << name << "\n";

    return 0;
}
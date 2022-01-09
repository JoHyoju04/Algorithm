#include <iostream>
#include <set>
#include <string>
using namespace std;

int n, k;
int cards[11];
bool visited[11];
set<string> s;

void dfs(int cnt, string str) {
    if (cnt == k) {
        s.insert(str);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            string tmp = str;
            str += to_string(cards[i]);
            dfs(cnt + 1, str);
            str = tmp;
            visited[i] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int answer = 0;

    cin >> n >> k;

    for (int i = 0; i < n; i++)    cin >> cards[i];

    dfs(0, "");

    answer = s.size();

    cout << answer;

    return 0;
}
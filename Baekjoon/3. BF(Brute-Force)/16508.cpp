#include <iostream>
#include <algorithm>
 
using namespace std;
struct book {
    int cost;
    char title[51];
};
char t[11];
int n;
book arr[16];
int cnt[26];
int select_cnt[26];
int ans = 987654321;
 
bool check() {
    for (int i = 0; i < 26; i++)
        if (cnt[i] > select_cnt[i])
            return false;
    return true;
}
 
void dfs(int idx, int total) {
    if (idx == n) {
        if (check())
            ans = min(ans, total);
        return;
    }
    for (int i = 0; arr[idx].title[i] != '\0'; i++)
        select_cnt[arr[idx].title[i] - 'A']++;
    dfs(idx + 1, total + arr[idx].cost);
    for (int i = 0; arr[idx].title[i] != '\0'; i++)
        select_cnt[arr[idx].title[i] - 'A']--;
    dfs(idx + 1, total);
}
 
int main() {
    cin >> t;
    for (int i = 0; t[i] != '\0'; i++)
        cnt[t[i] - 'A']++;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].cost >> arr[i].title;
    }
    dfs(0, 0);
    cout << (ans == 987654321 ? -1 : ans) << '\n';
    return 0;
}
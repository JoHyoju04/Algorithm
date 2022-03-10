#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

string str;
int L, C;
vector<char> words;
void dfs(int cnt, int idx) {
    if (cnt == L) {
        int one = 0, two = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u')   one++;
            else two++;
        }
        if (one >= 1 && two >= 2) cout << str << "\n";
        return;
    }
    for (int i = idx; i < C; i++) {
        str += words[i];
        dfs(cnt + 1, i + 1);
        str.pop_back();
    }
}

int main()
{
    cin >> L >> C;
    str = "";
    for (int i = 0; i < C; i++) {
        char input;
        cin >> input;
        words.push_back(input);
    }
    sort(words.begin(), words.end());
    dfs(0, 0);

    return 0;
}


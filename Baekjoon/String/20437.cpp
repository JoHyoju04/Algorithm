#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int t, k, n;
string w;
vector<int> alp[26], cand;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> w >> k;
        n = w.size();
        cand.clear();
        for (int i = 0; i < 26; i++) alp[i].clear();
        for (int i = 0; i < n; i++) alp[w[i] - 'a'].push_back(i);
        for (int i = 0; i < 26; i++) {
            if (alp[i].size() < k) continue;
            for (int st = 0; st + k - 1 < alp[i].size(); st++)
                cand.push_back(alp[i][st + k - 1] - alp[i][st] + 1);
        }
        if (cand.size() == 0) cout << -1 << '\n';
        else cout << *min_element(cand.begin(), cand.end()) << " " << *max_element(cand.begin(), cand.end()) << '\n';
    }
}
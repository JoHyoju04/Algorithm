#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> dish;
int kind[3001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,d,k,c,answer = 0, val;       
    cin >> n >> d >> k >> c;

    kind[c] = 1;
    int cnt = 1; 
    int l = 0, r = k - 1;

    for (int i = 0; i < n; i++) {
        cin >> val;
        dish.push_back(val);
        if (i < k) {
            kind[val]++;
            if (kind[val] == 1) cnt++;
        }
    }
    for (int i = 0; i < k; i++)
        dish.push_back(dish[i]);
    while (true) {
        answer = max(answer, cnt);
        if (l == n) break;
        kind[dish[l]]--;
        if (kind[dish[l++]] == 0) cnt--;
        kind[dish[++r]]++;
        if (kind[dish[r]] == 1) cnt++;
    }
    cout << answer;
    return 0;
}
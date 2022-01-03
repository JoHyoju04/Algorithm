#include <iostream>
#define MAX 2000001 
using namespace std;

int S[21];
bool num[MAX];
int N;

void dfs(int cnt, int idx, int sum) {
    num[sum] = true;
    if (cnt == N)  return;
    for (int i = idx; i < N; i++) {
        sum += S[i];
        dfs(cnt + 1, i+1, sum);
        sum -= S[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int answer=0;
    cin >> N;
    for (int i = 0; i < N; i++)    cin >> S[i];
    dfs(0, 0, 0);
    for (int i = 0; i < MAX; i++) {
        if (num[i]==false) {
            answer = i;
            break;
        }
    }
    cout << answer;
}
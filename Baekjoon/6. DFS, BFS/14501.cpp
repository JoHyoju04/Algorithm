#include <iostream>
using namespace std;
int N, answer = 0;
int reserve[17][3] = { 0, };
int work[3] = { 0, };
void DFS(int idx) {
    for (int i = idx; i <= N; i++) {
        if (work[0] <= i && (N - i + 1 >= reserve[i][0])) {
            int temp = work[0];
            work[0] = i + reserve[i][0];    //시간
            work[1] += reserve[i][1];   //수입
            DFS(idx + 1);
            work[0] = temp;
            work[1] -= reserve[i][1];
        }
    }
    answer = answer > work[1] ? answer : work[1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> reserve[i][0] >> reserve[i][1];
    }
    DFS(1);
    cout << answer;
    return 0;
}
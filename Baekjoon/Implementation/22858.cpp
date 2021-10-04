#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    vector<int> before, after, D;
    
    cin >> N >> K;
    
    before.assign(N, 0);
    after.assign(N, 0);
    D.assign(N, 0);

    for (int i = 0; i < N; i++)    cin >> after[i];
    for (int i = 0; i < N; i++)    cin >> D[i];

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            before[D[j] - 1] = after[j];
        }
        after = before;
    }

    for (int i = 0; i < N; i++)    cout << before[i] << " ";

    return 0;
}
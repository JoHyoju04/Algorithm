#include <iostream>
#include <vector>
using namespace std;
int n, m, aIdx, bIdx;
vector<int> A, B, answer;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n>>m;
    A.assign(n, 0);
    B.assign(m, 0);
    for (int i = 0; i < n; i++) cin>>A[i];
    for (int i = 0; i < m; i++)    cin >> B[i];
    
    for (int i = 0; i < n+ m; i++) {
        if (bIdx == m || aIdx<n&& A[aIdx] < B[bIdx]) {
            answer.push_back(A[aIdx++]);
        }
        else if (aIdx == n || bIdx<m&& B[bIdx] <= A[aIdx]) {
            answer.push_back(B[bIdx++]);
        }
    }

    for (int i = 0; i < answer.size(); i++)    cout << answer[i] << " ";
    return 0;
}

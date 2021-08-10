#include <iostream>
#include <vector>
using namespace std;

int A[100001];
int n,m;
vector<long long> sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    sum.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (i == 0)    sum[0] = A[0];
        else  sum[i] = sum[i - 1] + A[i];
    }
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        cout << sum[end-1] - sum[start-1] + A[start-1] << "\n";
    }
    
    return 0;
}
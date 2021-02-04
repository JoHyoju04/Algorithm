#include<iostream>
#include<vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<int> A;
vector<long> sum;
vector<long> result;
int N;
int op[4] = { 0, };
void Calculate(int idx, int oper) {
    switch (oper)
    {
    case 0:
        sum[idx] = sum[idx - 1] + A[idx];
        break;
    case 1:
        sum[idx] = sum[idx - 1] - A[idx];
        break;
    case 2:
        sum[idx] = sum[idx - 1] * A[idx];
        break;
    case 3:
        sum[idx] = abs(sum[idx - 1]) / A[idx];
        if (sum[idx - 1] < 0)    sum[idx] *= -1;
        break;
    default:
        break;
    }
}
void DFS(int index) {
    if (index == N)    result.push_back(sum[index - 1]);
    else {
        for (int i = 0; i < 4; i++) {
            if (op[i] != 0) {
                op[i]--;
                Calculate(index, i);
                DFS(index + 1);
                op[i]++;
            }
        }
    }
}
int main()
{
    cin >> N;
    A.assign(N, 0); sum.assign(N, 0);
    for (int i = 0; i < N; i++)    cin >> A[i];
    for (int j = 0; j < 4; j++)    cin >> op[j];
    sum[0] = A[0];
    DFS(1);
    sort(result.begin(), result.end());
    cout << result.back() << "\n" << result.front();
    return 0;
}


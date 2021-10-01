#include<iostream>
#include<cstring>
 
#define endl "\n"
#define MAX 10000 + 1
using namespace std;
 
int N;
int Arr[MAX];
int DP[MAX];
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Initialize()
{
    memset(Arr, 0, sizeof(Arr));
    memset(DP, 0, sizeof(DP));
}
 
void Input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
    }
}
 
void Solution()
{
    DP[0] = Arr[0] = 0;
    DP[1] = Arr[1];
    DP[2] = Arr[1] + Arr[2];
    for (int i = 3; i <= N; i++)
    {
        DP[i] = Bigger(DP[i - 3] + Arr[i - 1] + Arr[i], Bigger(DP[i - 2] + Arr[i], DP[i - 1]));
    }
}
 
void Solve()
{
    Initialize();
    Input();
    Solution();
 
    cout << DP[N] << endl;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
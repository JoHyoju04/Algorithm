#include<iostream>
#include<string>
#include<cstring>

#define MAX 510
#define endl "\n"
using namespace std;

int Len;
int LCS[MAX][MAX];
double Answer;
string A, B;

int Bigger(int A, int B) { if (A > B) return A; return B; }

void Initialize()
{
    memset(LCS, 0, sizeof(LCS));
}

void Input()
{
    cin >> Len;
    cin >> A >> B;
}

void Solution()
{
    for (int i = 1; i <= Len; i++)
    {
        for (int j = 1; j <= Len; j++)
        {
            if (A[i - 1] == B[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else LCS[i][j] = Bigger(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    Answer = (double)LCS[Len][Len] / (double)Len * 100.0;
}

void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();

        cout << "#" << T << " " << Answer << endl;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(2);
    Solve();

    return 0;
}
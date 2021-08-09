#include <iostream>
using namespace std;

int n, m, answer,low,high,sum;
int a[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n>>m;
    for (int i = 0; i < n; i++)    cin >> a[i];

    while(true) {
        if (sum >= m)  sum -= a[low++];
        else if (high == n)    break;
        else
        {
            sum += a[high++];
        }

        if (sum == m)  answer++;
    }
    cout << answer;
    return 0;
}
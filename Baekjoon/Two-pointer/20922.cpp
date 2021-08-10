#include <iostream>
#include <algorithm>
using namespace std;

int cnt[100001];
int n,k,answer;
int a[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int l = 0, r = 0; l < n; ++l) {
        while (r < n && cnt[a[r]] < k)
            ++cnt[a[r++]];
        answer = max(answer, r - l);
        --cnt[a[l]];
    }
    cout << answer;
    
    return 0;
}
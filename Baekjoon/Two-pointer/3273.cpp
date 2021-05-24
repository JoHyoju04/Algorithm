#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, x, cnt = 0;;
    vector<int> arr;
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++)    cin >> arr[i];
    cin >> x;
    sort(arr.begin(), arr.end());
    int low = 0, high = n - 1;
    while (low < high) {
        int n1 = arr[low], n2 = arr[high];
        if (n1 + n2 == x) {
            cnt++;
            low++;
            high--;
        }
        else if (n1 + n2 > x)    high--;
        else low++;
    }
    cout << cnt;
    return 0;
}
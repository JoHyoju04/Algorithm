/*
< 9095 : 1,2,3 더하기 >
기저 사례
sum[0]=1 : n이 1일 때, 방법의 수 -> 1
sum[1] =2 : n이 2일 때, 방법의 수 -> 1+1,2
sum[2] =4 : n이 3일 때, 방법의 수 -> 1+1+1,2+1,1+2,3

점화식 :
sum[j] =sum[j-1]+sum[j - 2] + score[j-3] : 1씩 더하면 되는 경우(차이가 1) + 2씩 더하면 되는 경우(차이가 2) + 3씩 더하면 되는 경우(차이가 3)

*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t, n;
    vector<int>sum;
    cin >> t;
    while (t--) {
        sum.push_back(1);
        sum.push_back(2);
        sum.push_back(4);
        cin >> n;
        for (int i = 3; i < n; i++)    sum.push_back(sum[i - 1] + sum[i - 2] + sum[i - 3]);
        cout << sum[n - 1] << "\n";
        sum.clear();
    }

    return 0;
}


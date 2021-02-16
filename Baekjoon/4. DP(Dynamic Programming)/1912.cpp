/*
< 1912 : 연속합 >
기저 사례
sum[0]=arr[0] : 처음 합을 arr[0]으로 시작한다.

점화식 :
sum[i]=max(arr[i],sum[i-1]+arr[i])
현재 인덱스(i)에서 arr[i] 또는 그 전 합(sum[i-1])과 arr[i]의 합 중에서 큰값을 선택한다.
->sum을 갱신할 때 마다 max값도 비교해서 갱신해준다.
*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long> arr(100001);
vector<long> sum(100001);
int main() {
    int N;
    long answer;
    cin >> N;
    for (int j = 0; j < N; j++)    cin >> arr[j];
    sum[0] = arr[0];
    answer = sum[0];
    for (int i = 1; i < N; i++) {
        sum[i] = max(arr[i], arr[i] + sum[i - 1]);
        answer = answer < sum[i] ? sum[i] : answer;
    }
    cout << answer;

    return 0;
}
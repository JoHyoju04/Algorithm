/*
< 1912 : ������ >
���� ���
sum[0]=arr[0] : ó�� ���� arr[0]���� �����Ѵ�.

��ȭ�� :
sum[i]=max(arr[i],sum[i-1]+arr[i])
���� �ε���(i)���� arr[i] �Ǵ� �� �� ��(sum[i-1])�� arr[i]�� �� �߿��� ū���� �����Ѵ�.
->sum�� ������ �� ���� max���� ���ؼ� �������ش�.
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
/*
< 1463 : 1�� ����� >
���� ���  nums�� index�� 1���� �����Ѵٰ� �����Ѵ�.(nums[0]=0���� �ǹ̾��� ���� �־���)
sum[1]=0 : N�� 1�� ��, ���� ���� ( 0�� )
sum[2] =1 : N�� 2�� ��, ���� ���� ( 2->1 )
sum[3] =1 : N�� 3�� ��, ���� ����  ( 3->1 )

��ȭ�� :
1. nums[i]=nums[i-1]+1 : 1�� �� ����� ���갳��
2. nums[i]=nums[i/2]+1 : 2�� ������ �������� 2�� ���� ����� ���갳��
3. nums[i]=nums[i/3]+1 : 3���� ������ �������� 3���� ���� ����� ���갳��
->1,2,3�� �߿� �ּҰ��� nums[i]�� �����Ѵ�.
  ��, 2���� i�� 2�� ������ �������� �ϰ� 3���� i�� 3���� ������ �������� �Ѵ�.

*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nums(1000001);
int main() {
    int N;
    cin >> N;
    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 1;
    nums[3] = 1;
    for (int i = 4; i <= N; i++) {
        nums[i] = nums[i - 1] + 1;
        if (i % 2 == 0 && nums[i / 2] + 1 < nums[i]) {
            nums[i] = nums[i / 2] + 1;
        }
        if (i % 3 == 0 && nums[i / 3] + 1 < nums[i]) {
            nums[i] = nums[i / 3] + 1;
        }

    }
    cout << nums[N];

    return 0;
}
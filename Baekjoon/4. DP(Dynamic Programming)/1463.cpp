/*
< 1463 : 1로 만들기 >
기저 사례  nums은 index가 1부터 시작한다고 가정한다.(nums[0]=0같은 의미없는 수를 넣어줌)
sum[1]=0 : N이 1일 때, 연산 개수 ( 0개 )
sum[2] =1 : N이 2일 때, 연산 개수 ( 2->1 )
sum[3] =1 : N이 3일 때, 연산 개수  ( 3->1 )

점화식 :
1. nums[i]=nums[i-1]+1 : 1을 뺀 경우의 연산개수
2. nums[i]=nums[i/2]+1 : 2로 나누어 떨어져서 2로 나눈 경우의 연산개수
3. nums[i]=nums[i/3]+1 : 3으로 나누어 떨어져서 3으로 나눈 경우의 연산개수
->1,2,3번 중에 최소값을 nums[i]에 갱신한다.
  단, 2번은 i가 2로 나누어 떨어져야 하고 3번도 i가 3으로 나누어 떨어져야 한다.

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
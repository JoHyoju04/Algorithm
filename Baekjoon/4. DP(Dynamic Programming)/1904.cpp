/*
< 1904 : 01타일 >
[DP]
기저 사례 : sum은 index가 1부터 시작한다고 가정한다.(sum[0]=0같은 의미없는 수를 넣어줌)
 sum[1]=1   //N이 1일때 만들 수 있는 수의 개수 (1)
 sum[2]=2   //N이 2일때 만들 수 있는 수의 개수 (00,11)
 
점화식 :
 i이 3이상일 때 예를 들어 i이 5인 경우
 [][][][][1]  마지막 자리수에 1이 올 수 있는 수의 개수 = 4로 만들 수 있는 수의 개수
 [][][][0][0]  마지막 자리수에 0이 올 수 있는 수의 개수(마지막자리-1의 자리도 0이 와야된다) = 3으로 만들 수 있는 수의 개수
                
 sum[i] = (sum[i - 1] + sum[i - 2])

*/

#include <iostream>
using namespace std;
long long sum[1000001];
int main() {
    int N;
    cin >> N;
    sum[1] = 1; sum[2] = 2;
    for (int i = 3; i <= N; i++)
        sum[i] = (sum[i - 1] + sum[i - 2]) % 15746;
    cout << sum[N];
    return 0;
}



/*
< 1904 : 계단오르기 >
기저 사례
sum[0]=score[0] :첫계단일 때 첫계단을 밟는 경우
sum[1] = max(score[0]+score[1],score[1]) : 두번째 계단일 때,  첫계단을 밟고 두번째 계단을 밟은 경우와 두번째 계단만 밟은 경우 중에 최댓값
sum[2] = max(score[0]+score[2],score[1]+score[2]) : 세번째 계단일 때,  첫계단을 밟고 세번째 계단을 밟은 경우와 두번째 계단과 세번째 계단을 밟은 경우 중에 최댓값

점화식 :
마지막 계단을 밟는 기준으로 점화식을 세운다
sum[j] =sum[j - 2] + score[j] :현재 계단(마지막계단)을 밟고 그 전전 계단을 밟는 경우
sum[j] = sum[j - 3] + score[j - 1] + score[j]) : 현재 계단(마지막계단)을 밟고 그 전 계단, 전전계단을 밟는 경우
->두 경우 중 최댓값을 선택한다.
*/
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    int score[301] = { 0, };
    int sum[301] = { 0, };
    cin >> n;
    for (int i = 0; i < n; i++)    cin >> score[i];
    sum[0] = score[0];
    sum[1] = max(score[0] + score[1], score[1]);
    sum[2] = max(score[0] + score[2], score[1] + score[2]);
    for (int j = 3; j < n; j++) {
        sum[j] = max(sum[j - 2] + score[j], sum[j - 3] + score[j - 1] + score[j]);
    }

    cout << sum[n - 1];
    return 0;
}


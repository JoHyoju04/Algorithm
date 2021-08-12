#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    for(int i = 0; i < cookie.size() - 1; i++){
        int leftSum = cookie[i];
        int rightSum = cookie[i + 1];
        int right = i;
        int left = i + 1;

        while(true){

            if(leftSum == rightSum)
                answer = max(answer, leftSum);

            if(leftSum > rightSum){
                if(right + 1 == cookie.size()) break;
                rightSum += cookie[++right];
            }
            else{
                if(left - 1 < 0) break;
                leftSum += cookie[--left];
            }            

        }
    }

    return answer;
}
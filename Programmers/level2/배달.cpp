#include <iostream>
#include <vector>
using namespace std;
#define MAX 987654321
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 1;
    vector<vector<int> > dp;
    dp.assign(51,vector<int>(51,MAX));
    for(int i=0;i<road.size();i++){
        if(dp[road[i][0]][road[i][1]]>road[i][2]){
            dp[road[i][0]][road[i][1]]=road[i][2];
            dp[road[i][1]][road[i][0]]=road[i][2];
        }
            
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j)    dp[i][j]=0;
                else if(dp[i][k]+dp[k][j]<dp[i][j])
                    dp[i][j]=dp[i][k]+dp[k][j];
            }
        }
    }
    
    for(int i=2;i<=N;i++){
        if(dp[1][i]<=K||dp[i][1]<=K){
            answer++;
        }
    }

    return answer;
}
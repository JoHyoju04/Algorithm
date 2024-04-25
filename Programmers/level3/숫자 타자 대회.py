weights =  [[1, 7, 6, 7, 5, 4, 5, 3, 2, 3]
        ,[7, 1, 2, 4, 2, 3, 5, 4, 5, 6]
        ,[6, 2, 1, 2, 3, 2, 3, 5, 4, 5]
        ,[7, 4, 2, 1, 5, 3, 2, 6, 5, 4]
        ,[5, 2, 3, 5, 1, 2, 4, 2, 3, 5]
        ,[4, 3, 2, 3, 2, 1, 2, 3, 2, 3]
        ,[5, 5, 3, 2, 4, 2, 1, 5, 3, 2]
        ,[3, 4, 5, 6, 2, 3, 5, 1, 2, 4]
        ,[2, 5, 4, 5, 3, 2, 3, 2, 1, 2]
        ,[3, 6, 5, 4, 5, 3, 2, 4, 2, 1]]
MAX=1e9
def solution(numbers):
    answer=MAX
    dp = [[[ MAX for _ in range(10)] for _ in range(10)] for _ in range(len(numbers)+1)]
    dp[0][4][6]=0
    for idx,strNum in enumerate(numbers):
        num = int(strNum)
        prevDP=dp[idx]
        nowDp=dp[idx+1]
        for i in range(10):
            for j in range(10):
                preValue = prevDP[i][j]
                if i==j or preValue==MAX: continue
                # 왼손이 움직인 경우
                if dp[idx+1][num][j]>preValue+weights[i][num]:
                    dp[idx+1][num][j]=preValue+weights[i][num]
                    
                # 오른손이 움직인 경우
                if dp[idx+1][i][num]>preValue+weights[j][num]:
                    dp[idx+1][i][num]=preValue+weights[j][num]
    for i in range(10):
        for j in range(10):
            answer=min(answer,dp[len(numbers)][i][j])
    return answer

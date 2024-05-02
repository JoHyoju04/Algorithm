def solution(sequence):
    answer = 0
    dp=[[0 for _ in range(len(sequence))] for _ in range(2)]
    for cnt in range(2):
        for idx,num in enumerate(sequence):
            if cnt==0:
                if (idx+1)%2==0:
                    dp[cnt][idx]=num
                else:
                    dp[cnt][idx]=num*-1
            else:
                if (idx+1)%2==0:
                    dp[cnt][idx]=num*-1
                else:
                    dp[cnt][idx]=num

    for i in range(2):
        for j in range(len(sequence)):
            if j==0:
                dp[i][j]=dp[i][j]
                continue
            dp[i][j]=max(dp[i][j],dp[i][j-1]+dp[i][j])

    for i in range(2):
        answer=max(answer,max(dp[i]))
            
                    
    return answer

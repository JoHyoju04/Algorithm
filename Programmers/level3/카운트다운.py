
INF = 987654321

# arr[0]은 싱글, 불로 만들 수 있는 점수
# arr[1]은 싱글, 불로 만들 수 없는 점수
def create_table():
    arr = []
    arr.append([i for i in range(1, 21)])
    arr[0].append(50)
    nxt = []
    for i in range(1, 21):
        for j in range(2, 4):
            ret = i * j
            
            if ret > 20:
                nxt.append(ret)
                
    arr.append(list(set(nxt)))
    
    return arr

def solution(target):
    table = create_table()
		
    #dp[점수][0]=해당 점수에 대한 0을 만들 수 있는 최대 횟수
    #dp[점수][1]=해당 점수에 대한 0을 만들 수 있는 싱글+불 최대 횟수
    dp = [[INF, 0] for _ in range(target + 1)]
    dp[0][0] = 0
		
    #점수 1~20까지 순회
    for i in range(1, target + 1):
	#(점수 - 다트) 점수의 모든 경우의 수 구하기
        for j in range(2):
            for k in range(len(table[j])):
                prev = i - table[j][k]

                if prev < 0:
                    continue

                total, valid = dp[prev][0] + 1, dp[prev][1] + 1 - j

                if total < dp[i][0]:
                    dp[i] = [total, valid]
                    
                elif total == dp[i][0]:
                    dp[i] = [total, max(dp[i][1], valid)]

    return dp[target]

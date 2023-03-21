import sys

input=sys.stdin.readline

INT_MAX = int(sys.maxsize)
dp=[ INT_MAX for _ in range(101)]
min_num=[0,0,1,7,4,2,0,8]

def get_max(num):
    return "7"*(num%2) + "1"*(num//2 - (num%2))

def get_min():
    dp[2]=1
    dp[3]=7
    dp[4]=4
    dp[5]=2
    dp[6]=6
    dp[7]=8
    dp[8]=10
    for i in range(9,101):
        for j in range(2,8):
            ss=str(dp[i-j])+str(min_num[j])
            dp[i]=min(dp[i],int(ss))

test_case=int(input())
nums=[int(input()) for _ in range(test_case)]
get_min()

for n in nums:
    print(dp[n],end=" ")
    print(get_max(n))

'''
def solutions(number):
    for i in range(len(number)):
        # 큰 수 구하기
        answer_max = '7' * (number[i] % 2) + '1' * (number[i] // 2 - (number[i] % 2))

        # 작은 수 구하기
        ans = [0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22]
        n = number[i]
        if n <= 10:
            answer_min = ans[n]
        else:
            answer_min = ''
            while n > 0:
                n -= 7
                if n >= 0:
                    answer_min += '8'
                else:
                    n += 7
                    break
            small = {2:'1', 5:'2', 6:'6'}
            if n in small:
                answer_min = small[n] + answer_min
            else:
                if n == 1:
                    answer_min = '10'+answer_min[1:]
                elif n == 3:
                    answer_min = '200'+answer_min[2:]
                elif n == 4:
                    answer_min = '20' + answer_min[1:]

        print(answer_min, end=' ')
        print(answer_max)

num = int(input())
number = [int(input()) for _ in range(num)]
solutions(number)
'''

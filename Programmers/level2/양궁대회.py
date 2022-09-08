def compare(arr, info):
    result = 0
    for i in range(11):
        if arr[i] > info[i]:
            result += 10-i
    return result

def solution(n, info):
    answer = []
    start = 0
    total = 0
    while start <= n:
        for i in range(start, 10-n+1):
            tempn = n
            arr = [0] * 11
            point = 0
            for j in range(i, 11):
                if tempn <= 0:
                    answer = arr[:] 
                    #계산
                    total = max(total, compare(arr, info))
                    print(answer, total)
                else:
                    if tempn > info[j]:
                        arr[j] = info[j] + 1
                        tempn -= info[j] + 1
                        #point += 10-i
            
        if tempn > 0:
            answer = [-1]
            print(-1)
            break
            
        start += 1
            
    return answer

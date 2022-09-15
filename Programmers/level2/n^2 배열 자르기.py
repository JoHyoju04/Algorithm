def solution(n, left, right):
    answer = []
                
    for num in range(left,right+1):
        r=num//n
        c=num%n
        answer.append(max(r,c)+1)
                
    return answer

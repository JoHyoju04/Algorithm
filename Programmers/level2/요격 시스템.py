def solution(targets):
    answer = 0
    targets.sort(key=lambda x:x[1])

    #요격 위
    loc=0
    for t in targets:
        #요격 위치보다 target의 시작 위치가 크거나 같으면 요격 위치 갱
        if loc<=t[0]:
            answer+=1
            loc=t[1]

    return answer

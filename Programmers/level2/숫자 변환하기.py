from collections import deque

def solution(x, y, n):
    answer = -1
    cnt=[0 for _ in range(1000001)]
    que=deque()
    que.append(x)
    cnt[x]=1

    while que:
        cur=que.popleft()

        if cur==y:
            answer=cnt[y]-1
            break

        if cur+n<=y and cnt[cur+n]==0:
            cnt[cur+n]=cnt[cur]+1
            que.append(cur+n)
        if cur*2<=y and cnt[cur*2]==0:
            cnt[cur*2]=cnt[cur]+1
            que.append(cur*2)
        if cur*3<=y and cnt[cur*3]==0:
            cnt[cur*3]=cnt[cur]+1
            que.append(cur*3)

    return answer

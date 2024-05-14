from collections import deque

def solution(n, m, x, y, r, c, k):
    answer = ''
    # 남은 거리 탐색 자주 해주어야 하므로 함수로 빼주기
    def manhattan(x1, y1):
        return abs(x1 - (r-1)) + abs(y1-(c-1))

    # k가 최단 거리보다 작거나, 최단 거리 - k가 홀수라면 도착지에 k번만에 도착 불가
    if manhattan(x-1, y-1) > k or (manhattan(x-1, y-1) - k) % 2:
        return 'impossible'
    # 탐색 방향 사전순으로 - d l r u
    direct = {(1,0):'d', (0,-1):'l', (0,1):'r', (-1,0):'u'}
    q = deque()
    q.append((x-1, y-1, 0, ''))
    while q:
        si, sj, cnt, route = q.popleft()
        # 도착했는데 남은 거리가 홀수라면 도착지에 k만큼 오지 못한다!
        if (si, sj) == (r-1, c-1) and (k-cnt) % 2:
            return 'impossible'
        elif (si, sj) == (r-1, c-1) and cnt == k:
            return route
        for di, dj in direct:
            ni, nj = si+di, sj+dj
            if 0<=ni<n and 0<=nj<m:
                # 다음 이동 자리를 보는 것이므로 +1 을 해주어야 함
                if m로nhattan(ni, nj) + cnt + 1 > k:
                    continue
                q.append((ni, nj, cnt+1, route+direct[(di, dj)]))
                # 사전 순이므
                break

    return answer


'''
import sys
sys.setrecursionlimit(5000)

answer=""
def dfs(depth,path,cr,cc):
    global answer
    
    if len(answer)!=0:
        return
    
    if K-len(path)<abs(cr-R)+abs(cc-C):
        return
    
    if K==len(path):
        answer=path
        return
    
    for dirs in ["d","l","r","u"]:
        nr,nc=cr,cc
        if dirs=="d":
            nr+=1
        elif dirs=="l":
            nc+=-1
        elif dirs=="r":
            nc+=1
        elif dirs=="u":
            nr+=-1
        if 0<nr<=N and 0<nc<=M:
            dfs(depth+1,path+dirs,nr,nc)
    

def solution(n, m, x, y, r, c, k):
    global N,M,R,C,K,answer
    
    N,M,R,C,K=n,m,r,c,k
    
    def manhattan(x1, y1):
        return abs(x1 - (r-1)) + abs(y1-(c-1))

    if manhattan(x-1, y-1) > k or (manhattan(x-1, y-1) - k) % 2:
        return 'impossible'
    
    dfs(0,"",x,y)
    
    if len(answer)==0:
        return "impossible"
    
    return answer
'''

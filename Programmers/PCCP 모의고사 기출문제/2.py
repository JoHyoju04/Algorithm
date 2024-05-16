from collections import deque

dirs=[[0,1],[0,-1],[1,0],[-1,0]]

def OOB(r,c):
    return not (0<=r<N and 0<=c<M)

def bfs(i,j,land):
    que=deque()
    visited[i][j]=True
    size=1
    col=set()
    col.add(j)
    que.append([i,j])
    while que:
        cc,cr=que.popleft()
        for a,b in dirs:
            nr=cc+a
            nc=cr+b
            if not OOB(nr,nc) and land[nr][nc]==1 and not visited[nr][nc]:
                visited[nr][nc]=True
                size+=1
                col.add(nc)
                que.append([nr,nc])
    for c in col:
        cnt[c]+=size
    
def solution(land):
    global N,M,visited,cnt
    
    answer = 0
    N=len(land)
    M=len(land[0])
    cnt=[0 for _ in range(M)]
    visited=[[0 for _ in range(M)] for _ in range(N)]
    
    for i in range(N):
        for j in range(M):
            if land[i][j]==1 and not visited[i][j]:
                bfs(i,j,land)
    answer=max(cnt)
                    
    return answer

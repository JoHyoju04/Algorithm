import sys
from collections import deque
import copy
input=sys.stdin.readline

def bfs(new_vi):
    global answer

    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    visited=[[0 for _ in range(N)]for _ in range(N)]
    que=deque()
    cnt=zero_cnt

    for r,c in new_vi:
        que.append([r,c,0])
        visited[r][c]=1
    
    while que:
        r,c,t=que.popleft()

        for a,b in dir:
            nr=r+a
            nc=c+b
            if 0<=nr<N and 0<=nc<N and (board[nr][nc]==0 or board[nr][nc]==2) and visited[nr][nc]==0:
                visited[nr][nc]=t+1
                que.append([nr,nc,t+1])
                if board[nr][nc]==0:
                    cnt-=1
                if cnt==0:
                    answer=min(answer,t+1)
                    return

    
def dfs(depth,idx,new_vi):
    if depth==M:
        bfs(new_vi)
        return
    for i in range(idx,len(viruses)):
        new_vi.append(viruses[i])
        dfs(depth+1,i+1,new_vi)
        new_vi.pop()

N,M=map(int,input().split())
board=[]
viruses=[]
INF=int(1e9)
answer=INF
zero_cnt=0
for i in range(N):
    board.append(list(map(int,input().split())))
    for j in range(N):
        if board[i][j]==2:
            viruses.append([i,j])
        elif board[i][j]==0:
            zero_cnt+=1

if zero_cnt>0:
    dfs(0,0,[])
elif zero_cnt==0:
    answer=0

if answer==INF:
    answer=-1
print(answer)

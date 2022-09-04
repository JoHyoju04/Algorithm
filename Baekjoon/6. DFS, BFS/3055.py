import sys
from collections import deque

input=sys.stdin.readline

def bfs(s_que,w_que,R,C):
    global board,visited
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    time=0
    while s_que:
        #물 확장
        w_size=len(w_que)
        for _ in range(w_size):
            r,c=w_que.popleft()
            for a,b in dir:
                nr=r+a
                nc=c+b
                if 0<=nr<R and 0<=nc<C and (board[nr][nc]=='.' or board[nr][nc]=='S'):
                    w_que.append([nr,nc])
                    board[nr][nc]='*'
        
        #고슴도치 이동
        s_size=len(s_que)
        for _ in range(s_size):
            r,c=s_que.popleft()
            if board[r][c]=='D':
                return time
            
            for a,b in dir:
                nr=r+a
                nc=c+b
                if 0<=nr<R and 0<=nc<C and (board[nr][nc]=='.' or board[nr][nc]=='D') and not visited[nr][nc]:
                    s_que.append([nr,nc])
                    visited[nr][nc]=True
        time+=1
    return 0


R,C=map(int,input().split())
board=[]
s_que=deque()
w_que=deque()
visited=[[ False for _ in range(C)] for _ in range(R)]

for i in range(R):
    s=input()
    for j in range(C):
        if s[j]=='S':
            s_que.append([i,j])
            visited[i][j]=True
        elif s[j]=='*':
            w_que.append([i,j])
    s=list(s)
    board.append(s)
    

answer=bfs(s_que,w_que,R,C)

if answer==0:
    print("KAKTUS")
else:
    print(answer)

import sys
from collections import deque

input=sys.stdin.readline

def bfs(R,C,jh,fire):
    global board
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    cnt=[ [0 for _ in range(C)] for _ in range(R)]
    ret=-1
    sr,sc=-1,-1

    while jh:
        new_fire=deque()
        while fire:
            r,c=fire.popleft()

            for a,b in dir:
                nr=r+a
                nc=c+b
                if 0<=nc<C and 0<=nr<R:
                    if board[nr][nc]=='.' or board[nr][nc]=='J':
                        board[nr][nc]='F'
                        new_fire.append([nr,nc])
        
        while new_fire:
            r,c=new_fire.popleft()
            fire.append([r,c])

        jh_size=len(jh)
        for _ in range(jh_size):
            r,c=jh.popleft()
            if sr==-1 and sc==-1:
                cnt[r][c]=1
                sr=r
                sc=c

            if r==R-1 or c==C-1 or r==0 or c==0:
                ret=cnt[r][c]
                break

            for a,b in dir:
                nc=a+c
                nr=b+r
                if 0<=nc<C and 0<=nr<R:
                    if board[nr][nc]=='.' and cnt[nr][nc]==0:
                        cnt[nr][nc]=cnt[r][c]+1
                        jh.append([nr,nc])
        if ret != -1:
            break


    return ret

R,C=map(int,input().split())
board=[]
jh=deque()
fire=deque()

for i in range(R):
    l=list(input())[:-1]
    for j in range(C):
        if l[j]=='J':
            jh.append([i,j])
        if l[j]=='F':
            fire.append([i,j])
    board.append(l)

answer=bfs(R,C,jh,fire)
if answer==-1:
    print("IMPOSSIBLE")
else:
    print(answer)





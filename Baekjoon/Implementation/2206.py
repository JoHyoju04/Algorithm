import sys
from collections import deque

def bfs(sr,sc):
    global answer
    queue=deque()
    queue.append([sr,sc,0])
    cnt[sr][sc][0]=1

    while queue:
        r,c,check=queue.popleft()

        if r==n-1 and c==m-1:
            answer=min(answer,cnt[r][c][check])

        for a,b in dir:
            nr=a+r
            nc=b+c
            if 0<=nr<n and 0<=nc<m:
                if board[nr][nc]==1 and check==0:
                    cnt[nr][nc][1]=cnt[r][c][0]+1
                    queue.append([nr,nc,1])
                elif board[nr][nc]==0 and cnt[nr][nc][check]==0:
                    cnt[nr][nc][check]=cnt[r][c][check]+1
                    queue.append([nr,nc,check])
    
    return -1



if __name__ == '__main__':
    input=sys.stdin.readline
    n,m=map(int,input().split())
    board=[]
    answer=987654321
    for i in range(n):
        board.append(list(map(int, input().strip())))
    
    cnt = [[[0] * 2 for _ in range(m)] for _ in range(n)]
    
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    bfs(0,0)
    if answer==987654321:
        answer=-1
    print(answer)

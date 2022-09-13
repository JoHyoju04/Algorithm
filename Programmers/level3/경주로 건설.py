from collections import deque

def bfs(board,s_dir):
    dir=[[0,1],[1,0],[0,-1],[-1,0]]
    INF=int(1e9)
    R=len(board)
    C=len(board[0])
    
    costs=[[ INF for _ in range(C)] for _ in range(R)]

    #큐 사용
    q=deque()
    q.append([0,s_dir,0,0])
    ans=INF
    while q:
        cost,before_dir,r,c=q.popleft()
        
        if r==R-1 and c==C-1:
            continue
        
        for idx,v in enumerate(dir):
            nr=v[0]+r
            nc=v[1]+c
            if 0<=nr<R and 0<=nc<C and board[nr][nc]==0:
                sum=600
                if before_dir == idx:
                    sum=100
                    
                #부등호 주의
                if sum+cost <= costs[nr][nc]:
                    q.append([sum+cost,idx,nr,nc])
                    costs[nr][nc]=sum+cost
        
    return costs[-1][-1]

def solution(board):
    #동쪽,남쪽 시작 방향 다르게 탐
    answer = min(bfs(board,0),bfs(board,1))
    return answer

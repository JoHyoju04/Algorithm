import sys
from collections import deque
import copy

input=sys.stdin.readline

def rotate():
    global board
    ori_board=copy.deepcopy(board)
    for i in range(N):
        for j in range(N):
            nr=(N-1)-j
            nc=i
            board[nr][nc]=ori_board[i][j]

def down():
    global board
    for i in range(N):
        for j in range(N-1,-1,-1):
            if board[j][i]>=0:
                mr,mc=j,i

                while True:
                    mr+=1
                    if mr>=N or board[mr][mc] != -2:
                        mr-=1
                        break

                    if board[mr][mc]==-2:
                        continue

                num=board[j][i]
                board[j][i]=-2
                board[mr][mc]=num




def bfs(r,c):
    global answer,max_cnt,max_zero,max_group
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    b_visited=[[False for _ in range(N)]for _ in range(N)]
    que=deque()

    b_visited[r][c]=True
    visited[r][c]=True
    que.append([r,c])
    b_num=board[r][c]
    cnt,zero=1,0
    block=[r,c]

    while que:
        rr,cc=que.popleft()

        for a,b in dir:
            nr=a+rr
            nc=b+cc
            if 0<=nr<N and 0<=nc<N:
                if (board[nr][nc]==b_num or board[nr][nc]==0) and b_visited[nr][nc]==False:
                    que.append([nr,nc])
                    b_visited[nr][nc]=True
                    visited[nr][nc]=True
                    if board[nr][nc]==0:
                        zero+=1
                    else:
                        if nr<block[0]:
                            block=[nr,nc]
                        elif nr==block[0] and nc<block[1]:
                            block = [nr, nc]
                    cnt+=1



    if cnt==1:
        return

    if cnt>max_cnt:
        max_cnt=cnt
        max_zero=zero
        max_group=copy.deepcopy(b_visited)
        max_block[0]=block[0]
        max_block[1]=block[1]
    elif cnt==max_cnt:
        if max_zero<zero:
            max_cnt = cnt
            max_zero = zero
            max_group = copy.deepcopy(b_visited)
            max_block[0] = block[0]
            max_block[1] = block[1]
        elif max_zero==zero:
            if max_block[0]<block[0]:
                max_cnt = cnt
                max_zero = zero
                max_group = copy.deepcopy(b_visited)
                max_block[0] = block[0]
                max_block[1] = block[1]
            elif max_block[0]==block[0] and max_block[1]<block[1]:
                max_cnt = cnt
                max_zero = zero
                max_group = copy.deepcopy(b_visited)
                max_block[0] = block[0]
                max_block[1] = block[1]
    return


if __name__ == '__main__':
    N,M=map(int,input().split())
    answer=0
    board=[]
    visited=[[False for _ in range(N)]for _ in range(N)]

    for _ in range(N):
        board.append(list(map(int,input().split())))

    while True:
        max_group = [[False for _ in range(N)] for _ in range(N)]
        max_cnt = 0
        max_zero = 0
        max_block = [N, N]
        visited = [[False for _ in range(N)] for _ in range(N)]

        for i in range(N):
            for j in range(N):
                if board[i][j]>0 and visited[i][j]==False:
                    bfs(i,j)

        #갱신이 안되면(그룹 못찾으면) 종료
        if max_cnt==0:
            break

        #점수 갱신, 제거
        answer+=max_cnt*max_cnt
        for i in range(N):
            for j in range(N):
                if max_group[i][j]==True:
                    board[i][j]=-2

        #중력
        down()

        #반시계 방향 90도 회전
        rotate()

        down()

    print(answer)


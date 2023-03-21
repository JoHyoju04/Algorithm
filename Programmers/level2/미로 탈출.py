from collections import deque
def solution(maps):
    answer = -1
    R,C=len(maps),len(maps[0])
    que=deque()
    visited=[[[0 for _ in range(C)] for _ in range(R)] for _ in range(2) ]
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    for i in range(R):
        for j in range(C):
            if maps[i][j]=='S':
                #r,c,l_check(0이면 레버 당기지 않음,1이면 레버 당김)
                que.append([i,j,0])
                visited[0][i][j]=1
    
    while que:
        cr,cc,lever=que.popleft()
        
        if maps[cr][cc]=='E' and lever==1:
            answer=visited[lever][cr][cc]-1
            break
            
        for a,b in dir:
            nr=cr+a
            nc=cc+b
            if 0<=nr<R and 0<=nc<C and visited[lever][nr][nc]==0:
                if maps[nr][nc] != 'X' and maps[nr][nc] != 'L':
                    que.append([nr,nc,lever])
                    visited[lever][nr][nc]=visited[lever][cr][cc]+1
                elif maps[nr][nc] == 'L':
                    que.append([nr,nc,1])
                    visited[1][nr][nc]=visited[lever][cr][cc]+1
    
    return answer

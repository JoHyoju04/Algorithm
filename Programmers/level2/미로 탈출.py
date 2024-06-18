from collections import deque
dirs=[[0,1],[0,-1],[1,0],[-1,0]]
def bfs(startLoc,endLoc,maps):
    visited=[[0 for _ in range(C)] for _ in range(R)]
    que=deque()
    visited[startLoc[0]][startLoc[1]]=1
    que.append(startLoc)
    
    while que:
        curLoc=que.popleft()
        if curLoc[0]==endLoc[0] and curLoc[1]==endLoc[1]:
            return visited[endLoc[0]][endLoc[1]]-1
        for i,j in dirs:
            nr=curLoc[0]+i
            nc=curLoc[1]+j
            if nr<0 or nr>=R or nc<0 or nc>=C or visited[nr][nc]>0:
                continue
            if maps[nr][nc]!='X':
                visited[nr][nc]=visited[curLoc[0]][curLoc[1]]+1
                que.append([nr,nc])
    return -1
                
def solution(maps):
    global R,C
    answer=0
    R=len(maps)
    C=len(maps[0])
    startLoc,leverLoc,exitLoc=[0,0],[0,0],[0,0]
    for i in range(R):
        for j in range(C):
            if maps[i][j]=='S':
                startLoc=[i,j]
            elif maps[i][j]=='E':
                exitLoc=[i,j]
            elif maps[i][j]=='L':
                leverLoc=[i,j]
    startToLeverTime=bfs(startLoc,leverLoc,maps)
    if startToLeverTime==-1:
        return -1
    leverToExitTime=bfs(leverLoc,exitLoc,maps)
    if leverToExitTime==-1:
        return -1
    return startToLeverTime+leverToExitTime
                
'''
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
'''

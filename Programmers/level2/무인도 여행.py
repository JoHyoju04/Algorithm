from collections import deque

def bfs(sr,sc,maps,visited):
    move=[[0,1],[0,-1],[1,0],[-1,0]]
    que=deque()
    que.append([sr,sc])
    visited[sr][sc]=True
    
    days=int(maps[sr][sc])
    
    while que:
        r,c=que.popleft()
        
        for a,b in move:
            nr=a+r
            nc=b+c
            if 0<=nr<len(maps) and 0<=nc<len(maps[0]) and visited[nr][nc]==False and maps[nr][nc] != 'X':
                que.append([nr,nc])
                visited[nr][nc]=True
                days+=int(maps[nr][nc])
    
    return days
    
def solution(maps):
    answer = []
    visited=[[False]*100 for _ in range(100)]
    
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if visited[i][j]==False and maps[i][j] != 'X':
                answer.append(bfs(i,j,maps,visited))
    
    if len(answer)==0:
        answer.append(-1)
    else:
        answer.sort()
        
    return answer

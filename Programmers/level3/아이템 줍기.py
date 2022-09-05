from collections import deque

def bfs(cx,cy,ix,iy,movable):
    que=deque()
    que.append([cx,cy])
    cnt=[[ 0 for _ in range(101)] for _ in range(101)]
    cnt[cy][cx]=1
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    while que:
        x,y=que.popleft()
        
        if x==ix and y==iy:
            return cnt[y][x]
        
        for a,b in dir:
            nx=x+a
            ny=y+b
            if 1<=nx<=100 and 1<=ny<=100 and movable[ny][nx] and cnt[ny][nx]==0:
                cnt[ny][nx]=cnt[y][x]+1
                que.append([nx,ny])
    return 0
            
        
def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    movable=[[ False for _ in range(101)] for _ in range(101)]
    
    for x1,y1,x2,y2 in rectangle:
        x1=x1*2
        x2=x2*2
        y1=y1*2
        y2=y2*2
        min_x=min(x1,x2)
        max_x=max(x1,x2)
        
        min_y=min(y1,y2)
        max_y=max(y1,y2)
        for x in range(min_x,max_x+1):
            movable[y1][x]=True
            movable[y2][x]=True
        for y in range(min_y,max_y+1):
            movable[y][x1]=True
            movable[y][x2]=True
    
    for i in range(101):
        for j in range(101):
            for x1,y1,x2,y2 in rectangle:
                if (x1*2)<j<(x2*2) and (y1*2)<i<(y2*2):
                    movable[i][j]=False
    
    answer=bfs(characterX*2, characterY*2, itemX*2, itemY*2,movable)-1
    answer=answer//2
    return answer

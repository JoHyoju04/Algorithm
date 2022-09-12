from collections import deque

def check_dist(r,c,cr,cc):
    dir_m=[[0,1],[0,-1],[1,0],[-1,0],[1,1],[1,-1],[-1,1],[-1,-1],[2,0],[-2,0],[0,2],[0,-2]]
    for a,b in dir_m:
        nr=r+a
        nc=c+b
        if cr==nr and cc==nc:
            return True
    
    return False

def bfs(place,now_r,now_c):
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    q=deque()
    visited=[[0 for _ in range(5)] for _ in range(5)]
    q.append([now_r,now_c])
    visited[now_r][now_c]=1
    
    while q:
        r,c=q.popleft()
        if not (r==now_r and c==now_c) and place[r][c]=='P':
            return False
        
        for a,b in dir:
            nr=a+r
            nc=b+c
            if 0<=nr<5 and 0<=nc<5:
                if check_dist(now_r,now_c,nr,nc) and visited[nr][nc]==False and place[nr][nc] != 'X':
                    q.append([nr,nc])
                    visited[nr][nc]=1
    
    return True
                    
def solution(places):
    answer = []
    for i in range(5):
        place=places[i]
        flag=False
        for j in range(5):
            for k in range(5):
                if place[j][k]=='P':
                    #맨해튼 거리에 p가 있다
                    if bfs(place,j,k)==False:
                        flag=True
                        break
            if flag:
                break
                
        if flag==False:
            answer.append(1)
        else:
            answer.append(0)
            
    return answer

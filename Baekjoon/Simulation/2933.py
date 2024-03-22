import sys
from collections import deque
input = sys.stdin.readline

def makeCluster(r,c,cnt,visited,clusterMaps):
    global maps,R,C
    que=deque()
    que.append([r,c])
    visited[r][c]=True
    clusterMaps[r][c]=cnt
    dir=[[0,1],[1,0],[0,-1],[-1,0]]
    while que:
        cr,cc= que.popleft()
        for a,b in dir:
            nr=cr+a
            nc=cc+b
            if 0>nr or nr>=R or 0>nc or nc>=C or maps[nr][nc]=='.' or visited[nr][nc]:
                continue
            que.append([nr,nc])
            visited[nr][nc]=True
            clusterMaps[nr][nc]=cnt

R,C = map(int,input().split())
maps=[]
for _ in range(R):
    maps.append(list(input().rstrip()))
N=int(input())
H=list(map(int, input().split()))
for order in range(1,N+1):
    ## 왼 -> 오
    if order%2 !=0:
        for i in range(C):
            if maps[R-H[order-1]][i] == 'x':
                maps[R-H[order-1]][i]='.'
                break
    ## 왼 <- 오
    else:
        for i in range(C-1,-1,-1):
            if maps[R-H[order-1]][i] == "x":
                maps[R-H[order-1]][i]="."
                break

    cnt=0
    visited=[[False]*C for _ in range(R)]
    clusterMaps=[[0]*C for _ in range(R)]
    for r in range(R):
        for c in range(C):
            if maps[r][c] == 'x' and visited[r][c] == False:
                cnt+=1
                makeCluster(r,c,cnt,visited,clusterMaps)

    groundMinerals=[]
    for r in range(R-1,-1,-1):
        for c in range(C):
            if r == R-1 and clusterMaps[r][c] > 0 and clusterMaps[r][c] not in groundMinerals:
                groundMinerals.append(clusterMaps[r][c])
    notGroundMinerals=[]

    for c in range(1,cnt+1):
        if c not in groundMinerals:
            notGroundMinerals.append(c)

    for mineral in notGroundMinerals:
        bottomMinerals=[]
        for c in range(C):
            for r in range(R-1,-1,-1):
                minR=R
                if clusterMaps[r][c]==mineral:
                    if minR>=r:
                        minR=r
                        bottomMinerals.append([r,c])
                    break
        moveCnt=R
        for r,c in bottomMinerals:
            for nr in range(r+1,R):
                if maps[nr][c]=="x":
                    moveCnt=min(moveCnt,nr-r-1)
                if maps[nr][c]=="." and nr==R-1:
                    moveCnt = min(moveCnt, nr - r)
        for c in range(C):
            for r in range(R-1,-1,-1):
                if clusterMaps[r][c]==mineral:
                    maps[r][c]='.'
                    maps[r+moveCnt][c]="x"

for i in range(R):
    print(*maps[i],sep="")


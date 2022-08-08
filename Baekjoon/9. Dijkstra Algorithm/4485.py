import heapq
import sys

input=sys.stdin.readline
INF=1e9
num=1

def dikjstra(num,n):
    q=[]
    heapq.heappush(q,(arr[0][0],0,0))
    cnt = [[INF for col in range(n)] for row in range(n)]

    while q:
        cost,r,c=heapq.heappop(q)

        if cost>cnt[r][c]: continue

        for a,b in dir:
            nr=r+a
            nc=c+b
            if nr<0 or nc<0 or nr>=n or nc>=n: continue

            if cnt[r][c]==INF or cnt[nr][nc]>arr[nr][nc]+cost:
                cnt[nr][nc]=arr[nr][nc]+cost
                heapq.heappush(q,(cnt[nr][nc],nr,nc))
    
    print("Problem "+str(num)+": "+str(cnt[n-1][n-1]))

while True:
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    n = int(input())
    if n==0: break

    arr=[0 for _ in range(n)]
    for i in range(n):
        arr[i]=list(map(int, input().split()))


    dikjstra(num,n)
    num+=1

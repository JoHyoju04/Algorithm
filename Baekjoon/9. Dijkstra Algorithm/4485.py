#13.AUG.2022

import sys
input=sys.stdin.readline
num=1
INF=987654321

def bfs(num,n):
        cnt = [[INF for col in range(n)] for row in range(n)]
        que=list()
        que.append((0,0))
        cnt[0][0]=arr[0][0]
        answer=INF
        while que:
            r,c=que.pop(0)
            
            if r==n-1 and c==n-1:
                answer=min(answer,cnt[n-1][n-1])

            for a,b in dir:
                nr=r+a
                nc=c+b
                if nr<0 or nc<0 or nr>=n or nc>=n: continue

                if cnt[nr][nc]==INF or cnt[nr][nc]>cnt[r][c]+arr[nr][nc]:
                    cnt[nr][nc]=cnt[r][c]+arr[nr][nc]
                    que.append((nr,nc))
    
        print("Problem "+str(num)+": "+str(cnt[n-1][n-1]))

while True:
    dir=[[0,1],[0,-1],[1,0],[-1,0]]
    n = int(input())
    if n==0: break

    arr=[0 for _ in range(n)]
    for i in range(n):
        arr[i]=list(map(int, input().split()))


    bfs(num,n)
    num+=1

'''
#09.AUG.2022
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
'''



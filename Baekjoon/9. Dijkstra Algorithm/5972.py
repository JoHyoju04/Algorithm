import heapq
import sys

def dikjstra(start):
    global dist
    q=[]
    heapq.heappush(q,(0,start))
    dist[start]=0

    while q:
        d,now=heapq.heappop(q)

        if d<dist[now]:
            continue

        for next,next_d in graph[now]:
            cost=next_d+dist[now]
            if cost<dist[next]:
                dist[next]=cost
                heapq.heappush(q,(cost,next))



input=sys.stdin.readline
n,m=map(int,input().split())
INF=int(1e9)
dist=[INF]*(n+1)
graph=[[] for _ in range(n+1)]

for _ in range(m):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

dikjstra(1)
print(dist[n])


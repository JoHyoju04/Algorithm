import sys
import heapq

input=sys.stdin.readline
N,M=map(int,input().split())
graph=[[] for _ in range(N+1)]
INF=int(1e9)
dist=[INF]*(N+1)

def dijkstra(start):
    que=[]
    heapq.heappush(que,(0,start))
    dist[start]=0

    while que:
        cost,cur=heapq.heappop(que)
        if cost>dist[cur]:
            continue
        for next,c in graph[cur]:
            if dist[next]>cost+c:
                dist[next]=cost+c
                heapq.heappush(que,(cost+c,next))

for _ in range(M):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

v1,v2=map(int,input().split())
startToV1,startToV2,v1ToV2,v1ToEnd,v2ToEnd=0,0,0,0,0

dijkstra(1)
startToV1=dist[v1]
startToV2=dist[v2]
dist=[INF]*(N+1)

dijkstra(v1)
v1ToV2,v1ToEnd=dist[v2],dist[N]
dist=[INF]*(N+1)

dijkstra(N)
v2ToEnd=dist[v2]

answer=min(startToV1+v1ToV2+v2ToEnd,startToV2+v1ToV2+v1ToEnd)
if answer>=INF:
    print(-1)
else:
    print(answer)

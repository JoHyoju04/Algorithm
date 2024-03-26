import sys
import heapq

input=sys.stdin.readline
hq=[]
arr=[]
answer=0
N=int(input())
for _ in range(N):
    heapq.heappush(hq,int(input()))

while len(hq)>1:
    n1=heapq.heappop(hq)
    n2=heapq.heappop(hq)
    answer+=n1+n2
    heapq.heappush(hq,n1+n2)

print(answer)

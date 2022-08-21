import heapq
import sys

input=sys.stdin.readline
n=int(input())
q=[]

for _ in range(n):
    x=int(input())
    if x==0:
        if len(q)==0:
            print(0)
        else:
            output=heapq.heappop(q)
            print(output)
    else:
        heapq.heappush(q,x)

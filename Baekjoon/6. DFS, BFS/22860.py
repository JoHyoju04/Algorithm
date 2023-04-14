import sys

input=sys.stdin.readline

N,M=map(int,input().split())
dct=dict()
cnt=0

def dfs(start,kinds):
    global cnt
    if start not in dct:
        return
    for f,check in dct[start]:
        if check==0:
            if f not in kinds:
                kinds.add(f)
            cnt+=1
        else:
            dfs(f,kinds)
            
for _ in range(N+M):
    P,F,C=input().split()
    if P not in dct:
        dct[P]=[]
        dct[P].append([F,int(C)])
    else:
        dct[P].append([F,int(C)])


Q=int(input())
for _ in range(Q):
    query=list(input().rstrip().split("/"))
    kinds=set()
    cnt=0
    dfs(query[-1],kinds)
    print(len(kinds),cnt)

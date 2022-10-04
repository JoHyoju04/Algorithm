import sys

input=sys.stdin.readline

N,M=map(int,input().split())
homes=[]
chickens=[]
answer=int(1e9)
for i in range(N):
    arr=list(map(int,input().split()))
    for j in range(N):
        if arr[j]==1:
            homes.append([i,j])
        elif arr[j]==2:
            chickens.append([i,j])

def cal_dist(new_chicken):
    sum=0
    for r,c in homes:
        min_dist=N*N
        for cr,cc in new_chicken:
            dist=abs(r-cr)+abs(c-cc)
            min_dist=min(min_dist,dist)
        sum+=min_dist
    return sum

def dfs(depth,idx,new_chicken):
    global answer
    if depth==M:
        answer=min(answer,cal_dist(new_chicken))
        return
    for i in range(idx,len(chickens)):
        new_chicken.append(chickens[i])
        dfs(depth+1,i+1,new_chicken)
        new_chicken.pop()

dfs(0,0,[])
print(answer)

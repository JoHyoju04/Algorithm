import sys

input = sys.stdin.readline
N=int(input())
eggs=[]
answer=0

for i in range(N):
    eggs.append(list(map(int,input().split())))

def dfs(idx): 
    global answer
    if idx==N:
        cnt=0
        for i in range(N) :
            if eggs[i][0]<=0 : cnt+=1
        answer=max(cnt,answer)
        return
    
    if(eggs[idx][0]<=0): 
        dfs(idx+1)
        return

    flag=0
    for i in range(N) :
        if i!=idx and eggs[i][0]>0:
            eggs[idx][0]-=eggs[i][1]
            eggs[i][0]-=eggs[idx][1]
            dfs(idx+1)
            eggs[idx][0]+=eggs[i][1]
            eggs[i][0]+=eggs[idx][1]
            flag=1
    if(flag==0) : dfs(N)
    
dfs(0)
print(answer)

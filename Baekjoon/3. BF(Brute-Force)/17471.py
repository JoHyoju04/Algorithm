import sys

input=sys.stdin.readline
def dfs(node,team_num):
    global visited
    visited[node]=True
    for next in graph[node]:
        if visited[next]==False and team[next]==team_num:
            dfs(next,team_num)

def check(team_num):
    global visited
    visited=[False]*(N+1)
    for i in range(1,N+1):
        if team[i]==team_num:
            dfs(i,team_num)
            break
    for i in range(1,N+1):
        if team[i]==team_num and visited[i]==False:
            return False

    return True

def divide(depth,idx):
    global answer
    if depth==N+1:
        return
    if depth!=1:
        if check(1) and check(2):
            one,two=0,0
            for i in range(1,N+1):
                if team[i]==1:
                    one+=people[i-1]
                else:
                    two+=people[i-1]
            sub=abs(one-two)
            answer=min(answer,sub)

    for i in range(idx,N+1):
        team[i]=1
        divide(depth+1,i+1)
        team[i]=2

N=int(input())
people=list(map(int,input().split()))
graph=[[] for _ in range(N+1)]
INF=int(1e9)
answer=INF

for i in range(1,N+1):
    arr=list(map(int,input().split()))
    for j in range(1,arr[0]+1):
        graph[i].append(arr[j])

team=[2 for _ in range(N+1)]

divide(1,1)

if answer==INF:
    answer=-1

print(answer)

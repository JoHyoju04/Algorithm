import sys
 
input=sys.stdin.readline

def dfs(v,i):
    visited[v]=True

    for w in adj[v]:
        if not visited[w]:
            dfs(w,i)
        elif w==i:
            result.append(w)

n=int(input())
adj=[[] for _ in range(n+1)]
result=[]

for i in range(n):
    adj[i+1].append(int(input()))
    
for i in range(1,n+1):
    visited=[False]*(n+1)
    dfs(i,i)

print(len(result))
for v in result:
    print(v)

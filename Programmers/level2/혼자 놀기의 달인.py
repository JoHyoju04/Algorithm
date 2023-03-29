visited=[False] * 101
cnts=[]

def dfs(depth,idx,cards):
    if visited[idx]:
        cnts.append(depth)
        return
    visited[idx]=True
    dfs(depth+1,cards[idx]-1,cards)
    
def solution(cards):
    answer = 0
    
    for i in range(len(cards)):
        if visited[i]==False:
            dfs(0,i,cards)
    cnts.sort(reverse=True)
    if len(cnts)!=1:
        answer=cnts[0]*cnts[1]
    
    return answer

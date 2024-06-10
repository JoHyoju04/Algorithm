import copy
import math
answer=25*50
remainPicks=[]
mineralIdx={"diamond":0,"iron":1,"stone":2}
tiredness=[[1,1,1],[5,1,1],[25,5,1]]
def dfs(depth,tools,picks,minerals):
    global answer
    if sum(remainPicks)==0 or depth == math.ceil(len(minerals)/5):
        sumTiredness=0
        idx=0
        for i,tool in enumerate(tools):
            for j in range(5):
                if idx>=len(minerals):
                    break
                sumTiredness += tiredness[tool][mineralIdx[minerals[idx]]]
                idx+=1
        answer=min(answer,sumTiredness)
        return
    for i in range(3):
        if remainPicks[i]>0:
            tools.append(i)
            remainPicks[i]-=1
            dfs(depth+1,tools,picks,minerals)
            remainPicks[i]+=1
            tools.pop()

def solution(picks,minerals):
    global answer,remainPicks
    remainPicks=copy.deepcopy(picks)
    dfs(0,[],picks,minerals)
    return answer

'''
needs=[[1,1,1],[5,1,1],[25,5,1]]
minerals_dict={"diamond":0,"iron":1,"stone":2}
min_num=0
answer = 1251

def dfs(start,picks,minerals):
    global answer,min_num
            
    if sum(picks)==0 or start==len(minerals):
        answer=min(min_num,answer)
        return
    
    for idx,val in enumerate(picks):
        if val>0:
            picks[idx]-=1
            tmp=min_num
            for m_idx in range(start,min(start+5,len(minerals))):
                m=minerals[m_idx]
                min_num+=needs[idx][minerals_dict[m]]
            dfs(min(start+5,len(minerals)),picks,minerals)
            picks[idx]+=1
            min_num=tmp
                
def solution(picks, minerals):
    global answer
    
    dfs(0,picks,minerals)
    
    return answer
'''

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

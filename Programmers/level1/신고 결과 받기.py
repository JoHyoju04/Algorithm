def solution(id_list, report, k):
    answer = []
    list_r=[[] for _ in range(len(id_list))]
    cnt=dict()
    for id in id_list:
        cnt[id]=0
    for ss in report:
        user,user_r=ss.split()
        for i,id in enumerate(id_list):
            if user==id:
                if user_r not in list_r[i]:
                    list_r[i].append(user_r)
                    cnt[user_r]+=1
                    break
    
    for li in list_r:
        num=0
        for u in li:
            if cnt[u]>=k:
                num+=1
        answer.append(num)
        
    return answer

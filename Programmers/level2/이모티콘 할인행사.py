discounts=[]
percents=[10,20,30,40]
candidate = []
def dfs(depth,users,emoticons):
    global discounts,percents,candidate
    
    if depth == len(emoticons):
        totalAmount,totalJoin=0,0
        for user in users:
            userRatio = user[0]
            userAmount = user[1]
            sumAmount=0
            for idx,dis in enumerate(discounts):
                if userRatio<=dis:
                    sumAmount += (emoticons[idx]-dis*0.01*emoticons[idx])
            if userAmount > sumAmount:
                totalAmount+=sumAmount
            else:
                totalJoin+=1
        candidate.append([totalJoin,totalAmount])
        return
    
    for p in percents:
        discounts.append(p)
        dfs(depth+1,users,emoticons)
        discounts=discounts[:-1]
        
def solution(users, emoticons):
    global candidate
    answer=[]
    dfs(0,users,emoticons)
    candidate = sorted(candidate,key=lambda x:(-x[0],-x[1]))
    answer=candidate[0]
    return answer

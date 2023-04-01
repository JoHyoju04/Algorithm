def time2min(t):
    ss=t.split(":")
    return int(ss[0])*60+int(ss[1])

def solution(plans):
    answer = []
    for p in plans:
        min_time=time2min(p[1])
        p[1]=min_time
        p[2]=int(p[2])
    plans.sort(key=lambda x:x[1])
    
    stop=[]
    cur=plans[0]
    nxt_idx=1
    print(plans)
    while True:
        #현재가 마지막 과제이면 바로 끝내기
        if nxt_idx==len(plans):
            answer.append(cur[0])
            break
            
        cur_time=cur[1]+cur[2]
        nxt_time=plans[nxt_idx][1]
        
        #새로운 과제 시작
        if cur_time>nxt_time:
            #과제 멈춤
            stop.append([cur[0],cur[2]-(plans[nxt_idx][1]-cur[1])])
            #마지막 과제이면 시작
            if nxt_idx==len(plans)-1:
                answer.append(plans[nxt_idx][0])
                break
            #다음 과제로
            cur=plans[nxt_idx]
            nxt_idx+=1
            continue
        else:
            #현재 과제 끝내기
            answer.append(cur[0])

            if cur_time<nxt_time:
                if len(stop)!=0:
                    arr=stop.pop()
                    cur=[arr[0],cur_time,arr[1]]
                    continue
        
            cur=plans[nxt_idx]
            nxt_idx+=1
                    
        
    if len(stop)!=0:
        stop.reverse()
        for s in stop:
            answer.append(s[0])
                
    return answer

'''
def solution(plans):
    answer = []
    arr = []
    for plan in plans:
        name = plan[0]
        h, m = map(int, plan[1].split(':'))
        t = int(plan[2])
        arr.append((name, h*60 + m, t))

    arr.sort(key= lambda x : x[1])
    st = []
    for i in range(len(arr)-1):
        n, s, t = arr[i]
        if s + t <= arr[i+1][1]:
            answer.append(n)
            tot = arr[i+1][1] - s - t
            while st:
                name, time = st.pop()
                if tot >= time:
                    tot -= time
                    answer.append(name)
                else:
                    st.append((name, time - tot))
                    break

        else:
            st.append((n, t - (arr[i+1][1] - s)))
    answer.append(arr[-1][0])

    while st:
        answer.append(st.pop()[0])
    return answer

'''

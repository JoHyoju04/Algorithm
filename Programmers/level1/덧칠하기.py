from bisect import bisect_right
def solution(n, m, section):
    answer = 0
    cur_s=0
    while cur_s<n:
        find_idx=bisect_right(section,cur_s)
        if find_idx<0 or find_idx>=len(section):
            break
        cur_s=section[find_idx]+m-1
        answer+=1
    return answer

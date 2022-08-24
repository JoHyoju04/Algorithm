import sys
input = sys.stdin.readline

n,k = map(int,input().rstrip().split())
l = list(map(int,input().rstrip().split()))

answer = 0
_dict = {}
left, right = 0, 0

while right < n:
    r_cnt = _dict.get(l[right],0)
    if r_cnt < k:
        _dict[l[right]] = _dict.get(l[right],0) + 1
        right+=1
    else:
        _dict[l[left]] = _dict.get(l[left],0) - 1
        left+=1
    answer = max(answer, right-left)

print(answer)

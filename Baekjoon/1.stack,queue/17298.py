import sys

input=sys.stdin.readline

n=int(input())
nums=list(map(int,input().split()))
stack=[]
nge=[0]*n

for i,v in enumerate(nums):
    while stack and nums[stack[-1]]<v:
        nge[stack.pop()]=v
    stack.append(i)


while stack:
    nge[stack.pop()]=-1

print(*nge)

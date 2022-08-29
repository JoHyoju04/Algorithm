import sys

input=sys.stdin.readline

n,m=map(int,input().split())
arr=[]
for _ in range(n):
    name,value=map(str,input().split())
    value=int(value)
    arr.append([name,value])

for _ in range(m):
    v=int(input())
    low=0
    high=n-1
    answer=0
    while low<=high:
        mid=(low+high)//2
        if arr[mid][1]<v:
            low=mid+1
        else:
            high=mid-1
            answer=mid

    print(arr[answer][0])

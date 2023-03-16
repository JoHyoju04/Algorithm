import sys
input=sys.stdin.readline


N=int(input())
nums=list(map(int,input().split()))
nums.sort()

M=int(input())
list_m=list(map(int,input().split()))

for m in list_m:
    low,high=0,N-1
    flag=False
    while low<=high:
        mid=(low+high)//2
        if m>nums[mid]:
            low=mid+1
        elif m<nums[mid]:
            high=mid-1
        else:
            flag=True
            break
    if flag:
        print("1",end=" ")
    else:
        print("0",end=" ")

import sys

n,x=map(int,input().split())
nums=list(map(int,input().split()))
sum=[0]*n

for idx in range(n):
    if idx==0:
        sum[0]=nums[0]
        continue
    sum[idx]=sum[idx-1]+nums[idx]

max_num=0
cnt=0
for idx in range(n):
    if idx+x-1>=n:
        break
    visit=sum[idx+x-1]-sum[idx]+nums[idx]
    if max_num<visit:
        max_num=visit
        cnt=1
    elif max_num==visit:
        cnt+=1

if max_num==0:
    print("SAD")
else:
    print(max_num)
    print(cnt)

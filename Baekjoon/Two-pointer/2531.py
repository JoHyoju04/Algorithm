import sys

if __name__ == '__main__':
    input=sys.stdin.readline
    n,d,k,c=map(int,input().split())
    l,r=0,0
    list=[]
    cnt=[0 for _ in range(d+1)]
    answer=0

    for _ in range(n):
        a=int(input())
        list.append(a)
    
    list+=list[:k-1]

    for i in range(k):
        cnt[list[i]]+=1

    
    r=k-1
    cnt[c]+=1
    while True:
        a=0
        for i in range(d+1):
            if cnt[i]>0:
                a+=1

        answer=max(answer,a)

        cnt[list[l]]-=1
        l+=1
        if r+1==len(list): break
        r+=1
        cnt[list[r]]+=1
        
    print(answer)
        

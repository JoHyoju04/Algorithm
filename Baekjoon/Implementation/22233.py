import sys

if __name__ == '__main__':
    input=sys.stdin.readline
    n,m=map(int,input().split())
    memo=dict()

    for _ in range(n):
        s=str(input())
        s=s[:-1]
        memo[s]=True
    
    for i in range(m):
        l=list(map(str,input().split(',')))
        l[len(l)-1]=l[len(l)-1][:-1]
        for s in l:
            if s in memo:
                del memo[s]
        print(len(memo))

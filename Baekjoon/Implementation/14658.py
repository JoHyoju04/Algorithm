import sys

def cal(x,y):
    global answer
    cnt=0
    for i in range(0,len(stars)):
        if x<=stars[i][0]<=x+l and y<=stars[i][1]<=y+l:
            cnt+=1
    answer=max(answer,cnt)

if __name__ == '__main__':
    input=sys.stdin.readline
    n,m,l,k=map(int,input().split())
    stars=[]
    answer=0

    for _ in range(k):
        a,b=map(int,input().split())
        stars.append([a,b])
    stars.sort()

    for i in range(0,len(stars)):
        for j in range(0,len(stars)):
            cal(stars[i][0],stars[j][1])

    answer=k-answer
    print(answer)

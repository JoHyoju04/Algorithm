import sys

input=sys.stdin.readline

def move_sand(r,c,d):
    global answer
    global N
    y=board[r][c]
    sum=0
    percent=[[]for _ in range(12)]
    percent[2].append([-2,0])
    percent[2].append([2,0])
    percent[1].append([-1,1])
    percent[1].append([1,1])
    percent[5].append([0,-2])
    percent[7].append([-1,0])
    percent[7].append([1,0])
    percent[10].append([-1,-1])
    percent[10].append([1,-1])
    percent[11].append([0,-1])
    num=[1,2,5,7,10,11]
    for i in range(12):
        if i not in num:
            continue
        for a,b in percent[i]:
            if d==1:
                b*=-1
                tmp=a
                a=b
                b=tmp
            elif d==2:
                b*=-1
            elif d==3:
                tmp=a
                a=b
                b=tmp

            nr=r+a
            nc=c+b
            #이동 모래양 계산    
            sand=int(float(i*0.01)*float(y))

            if i==11:
                sand=y-sum

            #알파가 아니면 이동 모래양 총합 더한다.
            if i<11:
                sum+=sand

            #벗어나면 answer에 더한다.
            if 0>nr or N<=nr or 0>nc or N<=nc:
                answer+=sand
                continue
            
            board[nr][nc]+=sand


    board[r][c]=0
    
N=int(input())
board=[]
for _ in range(N):
    board.append(list(map(int,input().split())))
dir=[[0,-1],[1,0],[0,1],[-1,0]]

answer=0
sr=N//2
sc=N//2
move_cnt=1
flag=False
while True:
    for _ in range(move_cnt):
        sr+=dir[0][0]
        sc+=dir[0][1]
        move_sand(sr,sc,0)
        if sr==0 and sc==0:
            flag=True
            break
    if flag:
        break
    for _ in range(move_cnt):
        sr+=dir[1][0]
        sc+=dir[1][1]
        move_sand(sr,sc,1)
    move_cnt+=1
    for _ in range(move_cnt):
        sr+=dir[2][0]
        sc+=dir[2][1]
        move_sand(sr,sc,2)
    for _ in range(move_cnt):
        sr+=dir[3][0]
        sc+=dir[3][1]
        move_sand(sr,sc,3)
    move_cnt+=1

print(answer)

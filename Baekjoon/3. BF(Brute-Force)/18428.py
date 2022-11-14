import sys

input=sys.stdin.readline

def monitor():
    global answer
    dir=[[0,1],[1,0],[0,-1],[-1,0]]
    all_flag=False
    #선생님 순회
    for r,c in loc_t:
        flag = False
        #상하좌우
        for a,b in dir:
            nr = r
            nc = c
            flag = False
            while True:
                nr=nr+a
                nc=nc+b
                if 0<=nr<N and 0<=nc<N:
                    if arr[nr][nc]=='O':
                        break
                    if arr[nr][nc]=='S':
                        flag=True
                        break
                else:
                    break
            if flag:
                break
        #한 선생님이 상하좌우 시 's'를 만났으면 all-flag=True
        if flag:
            all_flag=True
            break
    if all_flag==False:
        answer='YES'



def dfs(depth,idx):
    if answer=='YES':
        return
    if depth==3:
        monitor()
        return

    for i in range(idx,N*N):
        r=i//N
        c=i%N
        if arr[r][c]=='X':
            arr[r][c]='O'
            dfs(depth+1,i+1)
            arr[r][c]='X'

N=int(input())
arr=[]
loc_t=[]
for i in range(N):
    ss=input()
    arr.append(ss.split())
    for j in range(N):
        if arr[i][j]=='T':
            loc_t.append([i,j])

answer='NO'

dfs(0,0)
print(answer)

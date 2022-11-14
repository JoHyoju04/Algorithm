import sys

input=sys.stdin.readline

def dfs(depth,idx):
    global answer
    if depth==K-5:
        cnt=0
        for word in words:
            #한번도 안 사용했는지
            flag=False
            for c in word:
                #한번도 안 사용했다
                if used[ord(c)]==0:
                    flag=True
                    break
            if not flag:
                cnt+=1
        answer=max(answer,cnt)
        return

    for i in range(idx,ord(end_c)+1):
        if used[i]==0:
            used[i]=1
            dfs(depth+1,i+1)
            used[i]=0


start_c='a'
end_c='z'
N,K=map(int,input().split())
words=[]
used=[0 for _ in range(125)]
answer=0

for _ in range(N):
    words.append(str(input().strip()))

if K<5:
	print(0)
	exit()
elif K==26:
	print(N)
	exit()

ss="antatica"
for c in ss:
    used[ord(c)]=1

dfs(0,ord(start_c))
print(answer)

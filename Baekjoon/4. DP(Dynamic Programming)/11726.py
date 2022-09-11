import sys

input=sys.stdin.readline
N=int(input())

tile=[0]*1001

def tiling():
    global tile
    for i in range(1,1001):
        if i==1 or i==2:
            tile[i]=i
        else:
            tile[i]=(tile[i-1]+tile[i-2])%10007
tiling()
print(tile[N])

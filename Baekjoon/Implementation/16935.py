import sys
import copy

def upDown():
    global arr
    R = len(arr)
    C = len(arr[0])
    temp = copy.deepcopy(arr)
    for i in range(R):
        for j in range(C):
            arr[R-i-1][j]=temp[i][j]
def leftRight():
    global arr
    R = len(arr)
    C = len(arr[0])
    temp = copy.deepcopy(arr)
    for i in range(R):
        for j in range(C):
            arr[i][C-j-1] = temp[i][j]

def rightVertical():
    global arr
    R = len(arr)
    C = len(arr[0])
    temp = copy.deepcopy(arr)
    reverseTemp=[[0]*R for _ in range(C)]
    for i in range(R):
        for j in range(C):
            reverseTemp[j][R-i-1] = temp[i][j]
    arr=copy.deepcopy(reverseTemp)
def leftVertical():
    global arr
    R=len(arr)
    C=len(arr[0])
    temp = copy.deepcopy(arr)
    reverseTemp = [[0] * R for _ in range(C)]
    for i in range(R):
        for j in range(C):
            reverseTemp[C-j-1][i] = temp[i][j]
    arr = copy.deepcopy(reverseTemp)
def lotateRight():
    global arr
    R = len(arr)
    C = len(arr[0])
    temp = copy.deepcopy(arr)
    for i in range(R):
        for j in range(C):
            if 0<=i<R//2 and 0<=j<C//2:
                arr[i][j+C//2] = temp[i][j]
            elif 0<=i<R//2 and C//2<=j<C:
                arr[i+R//2][j]=temp[i][j]
            elif R//2<=i<R and C//2<=j<C:
                arr[i][j-C//2]=temp[i][j]
            elif R//2<=i<R and 0<=j<C//2:
                arr[i-R//2][j]=temp[i][j]
def lotateLeft():
        global arr
        R=len(arr)
        C=len(arr[0])
        temp = copy.deepcopy(arr)
        for i in range(R):
            for j in range(C):
                if 0 <= i < R // 2 and 0 <= j < C // 2:
                    arr[i+R//2][j]=temp[i][j]
                elif 0 <= i < R // 2 and C // 2 <= j < C:
                    arr[i][j - C // 2] = temp[i][j]
                elif R // 2 <= i < R and C // 2 <= j < C:
                    arr[i-R//2][j]=temp[i][j]
                elif R // 2<=i < R and 0 <= j < C//2:
                    arr[i][j+C//2]=temp[i][j]

input=sys.stdin.readline
N,M,R = map(int, input().split())
arr=[]
arr = [list(map(int, input().split())) for _ in range(N)]

operation = list(map(int, input().split()))
for op in operation:
    if op ==1:
        upDown()
    elif op == 2:
        leftRight()
    elif op==3:
        rightVertical()
    elif op==4:
        leftVertical()
    elif op==5:
        lotateRight()
    elif op==6:
        lotateLeft()

for i in arr:
    print(*i)
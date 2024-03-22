import sys
import copy

def rotate90(puzzle):
    R=len(puzzle)
    C=len(puzzle[0])
    temp=[[0]*R for _ in range(C)]
    for r in range(R):
        for c in range(C):
            temp[c][R-1-r]=puzzle[r][c]
    return temp


def rotate180(puzzle):
    R= len(puzzle)
    C=len(puzzle[0])
    temp=copy.deepcopy(puzzle)
    for r in range(R):
        for c in range(C):
            puzzle[R-1-r][C-1-c]=temp[r][c]
    return puzzle

def rotate270(puzzle):
    R = len(puzzle)
    C = len(puzzle[0])
    temp = [[0] * R for _ in range(C)]
    for r in range(R):
        for c in range(C):
            temp[C-1-c][r] = puzzle[r][c]
    return temp

def calculate(sumP,puzzle):
    minArea = 10001
    for i in range(100):
        for j in range(100):
            check = False
            for x in range(i,i+len(puzzle)):
                for y in range(j,j+len(puzzle[0])):
                    if sumP[x][y] == 1 and puzzle[x-i][y-j] == 1:
                        check = True
                        break
                if check:
                    break
            if check == False:
                min_y = min(i, 50);
                max_y = max(i + len(puzzle) - 1, 49 + len(puzzle1))
                min_x = min(j, 50);
                max_x = max(j + len(puzzle[0]) - 1, 49 + len(puzzle1[0]))
                area = (max_y - min_y + 1) * (max_x - min_x + 1)
                minArea = min(minArea, area)
    return minArea

input=sys.stdin.readline
N1,M1 = map(int,input().split())
puzzle1=[]
for _ in range(N1):
    puzzle1.append(list(map(int,input().rstrip())))
    # puzzle1.append(list(input().rstrip()))
N2,M2=map(int,input().split())
puzzle2=[]
for _ in range(N2):
    puzzle2.append(list(map(int,input().rstrip())))
# print(*puzzle1,sep="\n")
# print(*puzzle2,sep="\n")

sumPuzzle=[[0]*150 for _ in range(150)]
for i in range(N1):
    for j in range(M1):
        sumPuzzle[i+50][j+50]=puzzle1[i][j]
# print(*sumPuzzle,sep="\n")

answer=10001
originPuzzle2=copy.deepcopy(puzzle2)
#90도 회전
puzzle2=rotate90(puzzle2)
#맞춰보기
answer=min(answer,calculate(sumPuzzle,puzzle2))

#180도 회전
puzzle2=copy.deepcopy(originPuzzle2)
rotate180(puzzle2)
#맞춰보기
answer=min(answer,calculate(sumPuzzle,puzzle2))

#270도 회전
puzzle2=copy.deepcopy(originPuzzle2)
puzzle2=rotate270(puzzle2)
#맞춰보기
answer=min(answer,calculate(sumPuzzle,puzzle2))

print(answer)

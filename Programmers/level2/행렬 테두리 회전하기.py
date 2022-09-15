def solution(rows, columns, queries):
    answer = []
    arr=[ [0 for _ in range(columns)] for _ in range(rows)]
    num=1
    for i in range(rows):
        for j in range(columns):
            arr[i][j]=num
            num+=1
            
    for q in queries:
        x1,y1,x2,y2=q
        r,c=x1-1,y1-1
        tmp=arr[r][c]
        min_num=tmp
        
        for mr in range(r+1,x2):
            min_num=min(min_num,arr[mr][c])
            arr[mr-1][c]=arr[mr][c]
        
        
        for mc in range(c+1,y2):
            min_num=min(min_num,arr[x2-1][mc])
            arr[x2-1][mc-1]=arr[x2-1][mc]
        
        for mr in range(x2-2,r-1,-1):
            min_num=min(min_num,arr[mr][y2-1])
            arr[mr+1][y2-1]=arr[mr][y2-1]
        
        for mc in range(y2-2,c-1,-1):
            if mc==c:
                arr[r][mc+1]=tmp
                continue
            min_num=min(min_num,arr[r][mc])
            arr[r][mc+1]=arr[r][mc]
        answer.append(min_num)
        
    
    return answer

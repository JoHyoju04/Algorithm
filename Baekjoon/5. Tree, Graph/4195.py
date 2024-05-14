test_case = int(input())

# find 재귀 함수 : x의 찐부모를 찾을 떄 까지 find
def find(x):
    if x == parent[x]:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


# x의 부모를 찾고, y의 부모를 찾음. 서로 부모가 다르면 x의 부모를 일치시킴.
def union(x, y):
    x_ = find(x)
    y_ = find(y)

    # x, y 의 부모가 서로 다른 경우, x 부모로 일치. num 딕셔너리에 자식 수 셈.
    if x_ != y_:
        parent[y_] = x_
        num[x_] += num[y_]


for _ in range(test_case):
    friends = int(input())

    parent = dict()
    num = dict()
    for _ in range(friends):
        x, y = input().split()

        if x not in parent:
            parent[x] = x
            num[x] = 1
        if y not in parent:
            parent[y] = y
            num[y] = 1

        union(x, y)
        #부모에 카운트된 수 리턴
        print(num[find(x)])

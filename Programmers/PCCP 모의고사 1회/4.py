from queue import PriorityQueue

def call_programs(program, cur, q):
    while program and program[0][1] <= cur:
        q.put(program.pop(0))

def solution(program):
    answer = [0 for _ in range(10)]
    #대기 큐
    program.sort(key=lambda x: x[1])
    #실행 큐
    q = PriorityQueue() 
    cur = 0 

    while program or q.empty() == False: 
        if q.empty(): cur = program[0][1]
        else:  
            execute = q.get()
            answer[execute[0] - 1] += cur - execute[1]
            cur += execute[2] 

        call_programs(program, cur, q)

    return [cur, *answer]

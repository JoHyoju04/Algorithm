def toDate(day):
    arr=day.split('.')
    year=int(arr[0])*12*28
    month=int(arr[1])*28
    date=int(arr[2])
    
    return year+month+date

def solution(today, terms, privacies):
    answer = []
    terms_date=dict()
    today_date=toDate(today)
    
    for s in terms:
        arr=s.split()
        terms_date[arr[0]]=int(arr[1])*28
    
    for idx,value in enumerate(privacies):
        arr=value.split()
        date=toDate(arr[0])
        if terms_date[arr[1]]+date<=today_date:
            answer.append(idx+1)
    
    return answer

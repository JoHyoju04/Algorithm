def solution(keymap, targets):
    answer = []
    loc = {}
    for word in keymap:
        for i in range(len(word)):
            if word[i] in loc and loc[word[i]]<=i+1:
                continue
            loc[word[i]]=i+1
    
    for target in targets:
        cnt=0
        for ch in target:
            if ch in loc:
                cnt += loc[ch]
            else:
                cnt=0
                break
        if cnt==0:
            cnt=-1
        answer.append(cnt)
                
    return answer

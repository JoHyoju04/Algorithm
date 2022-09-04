def solution(s):
    min_len = len(s)
    for i in range(1, len(s) // 2 + 1):
        new_s = ''
        cnt = 1
        for j in range(0, len(s), i):
            print(j,j+i)
            if s[j:j+i] == s[j+i:j+2*i]:
                cnt += 1
            else:
                if (cnt != 1):
                    new_s += str(cnt)
                new_s += s[j:j+i]
                cnt = 1

        min_len = min(min_len, len(new_s))

    return min_len

import sys

def cutCables(length,cables):
    ret=0
    for c in cables:
        ret += c //length
    return ret

if __name__ == "__main__":
    input=sys.stdin.readline
    K, N = map(int, input().split())
    cables = [int(input()) for _ in range(K)]
    low=1
    high=max(cables)
    answer=0

    while low<=high:
        mid=(low+high)//2
        cnt=cutCables(mid,cables)
        if cnt<N:
            high=mid-1
        else:
            low=mid+1
            answer=mid

    print(answer)

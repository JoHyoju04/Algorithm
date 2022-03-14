#include <iostream>
#include <vector>
using namespace std;

int getInstallNum(int nonReachCnt, int w) {//기지국을 얼마나 설치해주면 되는지 구하는 함수
    int q, r;
    if (nonReachCnt > 0) {
        q = nonReachCnt / ((2 * w) + 1);
        r = nonReachCnt % ((2 * w) + 1);
        if (r == 0) return q + 1;
        else return q;
    }
    return 0;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, nonReachCnt;

    //처음
    nonReachCnt = (stations[0] - w - 1);
    answer += getInstallNum(nonReachCnt, w);

    //중간
    for (int i = 1; i < stations.size(); i++) {
        int before = stations[i - 1];
        int cur = stations[i];

        nonReachCnt = (cur - w) - (before + w) - 1;
        answer += getInstallNum(nonReachCnt, w);
    }

    //끝
    nonReachCnt = n - (stations[stations.size() - 1] + w);
    answer += getInstallNum(nonReachCnt, w);

    return answer;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, start = 1, index = 0;

    while(start <= n)
    {
        if(start >= stations[index] - w && start <= stations[index] + w)
        {
            start = stations[index] + w;
            index++;
        }
        else
        {
            start += 2 * w;
            answer++;
        }
        start++;
    }

    return answer;
}
*/
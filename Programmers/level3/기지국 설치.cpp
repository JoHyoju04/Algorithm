#include <iostream>
#include <vector>
using namespace std;

int getInstallNum(int nonReachCnt, int w) {//�������� �󸶳� ��ġ���ָ� �Ǵ��� ���ϴ� �Լ�
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

    //ó��
    nonReachCnt = (stations[0] - w - 1);
    answer += getInstallNum(nonReachCnt, w);

    //�߰�
    for (int i = 1; i < stations.size(); i++) {
        int before = stations[i - 1];
        int cur = stations[i];

        nonReachCnt = (cur - w) - (before + w) - 1;
        answer += getInstallNum(nonReachCnt, w);
    }

    //��
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
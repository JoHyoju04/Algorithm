/*
< 1700 : 멀티탭 스케줄링 >
-고려할 것

i) 해당 기기가 플러그에 꽂혀있는가
ii) 플러그에 빈 곳이 있는가
iii) 플러그에 빈 곳이 없는 경우

 - i) 와 ii) 같은 경우 콘센트를 뺄 필요가 없으므로 continue 해서 다음 기기를 확인

- iii) 경우 콘센트를 빼야합니다.
  a) 콘센트를 빼야하는데 어떤 콘센트를 빼야하는지를 탐욕적 선택
  b) 그리디하게 접근하면 이후에 단 한번도 쓰지 않을 기기를 빼거나 제일 마지막에 쓰일 기기를 빼는 것이 최적
  c) b에서 찾은 기기를 플러그에서 빼고 사용 예정이었던 기기를 꽂음

*/
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100 + 1;
int N, K;
int schedule[MAX], plug[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; i++)
        cin >> schedule[i];

    int result = 0;

    for (int i = 0; i < K; i++)
    {
        bool pluggedIn = false;
        //해당 기기가 꽂혀있는지 확인
        for (int j = 0; j < N; j++)
            if (plug[j] == schedule[i])
            {
                pluggedIn = true;
                break;
            }
        if (pluggedIn)
            continue;

        //비어있는 구멍 확인

        for (int j = 0; j < N; j++)
            if (!plug[j])
            {
                plug[j] = schedule[i];
                pluggedIn = true;
                break;
            }
        if (pluggedIn)
            continue;
        //가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾고

        int idx, deviceIdx = -1;

        for (int j = 0; j < N; j++)

        {
            int lastIdx = 0;
            for (int k = i + 1; k < K; k++)
            {
                if (plug[j] == schedule[k])
                    break;
                lastIdx++;
            }
            if (lastIdx > deviceIdx)
            {
                idx = j;
                deviceIdx = lastIdx;
            }
        }
        result++;
        //앞서 찾은 기기가 꽂혀있던 곳에 현재 꽂을 예정이였던 기기를 꽂음
        plug[idx] = schedule[i];
    }
    cout << result << "\n";
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000;
int N, K, D;
pair<int, pair<int, int>> rule[MAX];
//해당 박스 번호가 마지막이라고 가정했을 때 몇개의 도토리가 들어있는지
bool func(int mid)
{
    long long sum = 0;
    for (int i = 0; i < K; i++)
    {
        int high = min(rule[i].second.first, mid);
        if (high >= rule[i].first)
            sum += ((high - rule[i].first) / rule[i].second.second) + 1;
    }
    return sum >= D;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K >> D;
    for (int i = 0; i < K; i++)
        cin >> rule[i].first >> rule[i].second.first >> rule[i].second.second;
    int low = 0, high = N;
    int result = 0;
    while (low <= high) {
        //박스 번호
        int mid = (low + high) / 2;
        if (func(mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << result << "\n";
    return 0;
}
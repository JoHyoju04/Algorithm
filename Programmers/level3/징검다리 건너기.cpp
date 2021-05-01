#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> stones, int mid, int k)
{
    int count = 0;

    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid <= 0)
            count++;
        else
            count = 0;

        if (count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 1, high = *max_element(stones.begin(), stones.end());

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (check(stones, mid, k))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

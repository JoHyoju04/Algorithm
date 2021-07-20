#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    long long answer = 0;
    vector<int> rope;
    cin >> N;
    rope.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> rope[i];
    }
    sort(rope.begin(), rope.end());

    for (int i = 0; i < N; i++) {
        if(answer< rope[i] * (N - i))
            answer =  rope[i] * (N - i);
    }
    cout << answer;
    return 0;
}
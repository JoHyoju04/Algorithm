#include<iostream>
#include<cstring>
#include<queue>

#define MOD 20171109

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, A;
        priority_queue<int> maxH;
        priority_queue<int, vector<int>, greater<int> > minH;
        long long sum = 0;
        cin >> N >> A;
        maxH.push(A);
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            int num = maxH.top();
            maxH.pop();

            if (num < a)   minH.push(a);
            else maxH.push(a);

            if (num < b)   minH.push(b);
            else maxH.push(b);

            if (minH.size() > maxH.size()) {
                maxH.push(minH.top());
                minH.pop();
            }

            if (minH.size() == maxH.size())    maxH.push(num);
            else minH.push(num);

            sum = (sum + maxH.top()) % MOD;
        }

        cout << "#" << test_case << " " << sum << "\n";

        while (!minH.empty())    minH.pop();
        while (!maxH.empty())    maxH.pop();

    }
    return 0;
}
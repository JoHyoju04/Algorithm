#include<iostream>
#include<queue>
#define MAX 100010
using namespace std;

int N;
int Arr[MAX];

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> Arr[i];

    priority_queue<int> Max_PQ, Min_PQ;
    for (int i = 0; i < N; i++)
    {
        if (Max_PQ.size() > Min_PQ.size()) Min_PQ.push(-Arr[i]);
        else Max_PQ.push(Arr[i]);

        if (Max_PQ.empty() == false && Min_PQ.empty() == false)
        {
            if (Max_PQ.top() > -Min_PQ.top())
            {
                int Max_Value = Max_PQ.top();
                int Min_Value = -Min_PQ.top();

                Max_PQ.pop(); Min_PQ.pop();

                Max_PQ.push(Min_Value);
                Min_PQ.push(-Max_Value);
            }
        }
        cout << Max_PQ.top() << "\n";
    }

    return 0;
}
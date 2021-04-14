#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> edge;
vector<int> adjust[32001];
int N, M;

void TopologicalSort() {
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (!edge[i])
            q.push(i);

    for (int i = 1; i <= N; i++)
    {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        for (int j = 0; j < adjust[curr].size(); j++)
        {
            int next = adjust[curr][j];
            edge[next]--;
            if (!edge[next])
                q.push(next);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    edge.assign(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        adjust[n1].push_back(n2);
        edge[n2]++;
    }

    TopologicalSort();
    return 0;
}
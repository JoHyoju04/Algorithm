#include <vector>
#include<iostream>
using namespace std;
vector<int> adj[500002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    double W, leaf = 0;
    double answer = 0;
    cin >> N >> W;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 2; i <= N; i++) {
        if (adj[i].size() == 1)    leaf++;
    }
    answer = W / leaf;
    cout.precision(10);
    cout << fixed << answer << endl;

    return 0;
}

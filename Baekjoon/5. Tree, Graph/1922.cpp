#include<iostream>
#include<algorithm>
using namespace std;
struct network
{
    int i, j, cost;
};

int parent[1001];
int n,m;
vector<network> graph;

int find(int a) {
    if (parent[a] == a)    return a;
    return parent[a] = find(parent[a]);
}

void uni(int a, int b) {
    int x = find(a);
    int y = find(b);

    if (x == y)    return;
    parent[x] = y;
}

bool compare(network a, network b) {
    return a.cost < b.cost;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({ a,b,c });
    }
    for (int i = 1; i <= n; i++)    parent[i] = i;
    sort(graph.begin(), graph.end(), compare);
    long long answer = 0;
    for (int i = 0; i < m; i++) {
        int a = graph[i].i;
        int b = graph[i].j;

        if (find(a) != find(b)) {
            answer += graph[i].cost;
            uni(a, b);
        }
    }
    cout << answer;
    return 0;
}
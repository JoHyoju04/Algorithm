#include <iostream>
#include <vector>
using namespace std;
int N;
bool visited[100001];
int parent[100001];
vector<int> tree[100001];
void DFS(int num) {
    visited[num] = true;
    for (int i = 0; i < tree[num].size(); i++) {
        int child = tree[num][i];
        if (!visited[child]) {
            parent[child] = num;
            DFS(child);
        }
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }
    DFS(1);
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";

    return 0;
}
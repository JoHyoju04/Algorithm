#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> tree[51];
int delete_node;
void DFS(int node) {
    if (tree[node].size() == 0) {
        tree[node].push_back(-1);
        return;
    }
    for (int i = 0; i < tree[node].size(); i++) {
        int child = tree[node][i];
        tree[node][i] = -1;
        DFS(child);
    }
}

int main() {
    int answer = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int root;
        cin >> root;
        if (root == -1)    continue;
        tree[root].push_back(i);
    }
    cin >> delete_node;
    DFS(delete_node);
    for (int i = 0; i < N; i++) {
        if (tree[i].size() == 0 || (tree[i].size() == 1 && tree[i][0] == delete_node))
            answer++;
    }
    cout << answer;

    return 0;
}
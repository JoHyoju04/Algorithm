#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[55];
int N;
int rootNode;
int delNode;
int leafCnt;

void find_leaf(int node)
{
    if (graph[node].size() == 0)
    {
        leafCnt++;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        // 현재노드의 자식이 삭제할 노드이고, 
        if (graph[node][i] == delNode)
        {
            // 현재노드의 자식이 1개 밖에 없으면, 현재 노드의 자식을 삭제할 경우 그 현재 노드가 리프노드가 됨 
            if (graph[node].size() == 1)
            {
                leafCnt++;
            }

            continue;
        }

        find_leaf(graph[node][i]);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int to = 0; to < N; to++)
    {
        int from;
        cin >> from;

        if (from == -1)
        {
            rootNode = to;

            continue;
        }
        else
        {
            graph[from].push_back(to);
        }
    }

    cin >> delNode;

    if (delNode == rootNode)
    {
        cout << "0";
    }
    else
    {
        find_leaf(rootNode);
        cout << leafCnt;
    }

    return 0;
}
/*
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
*/
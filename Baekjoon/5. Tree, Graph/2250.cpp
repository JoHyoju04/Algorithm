#include <vector>
#include<iostream>
using namespace std;
vector<int> tree[10002];
vector<int> col;
vector<int >level[10002];
int n,width = 0;

void DFS(int start, int depth) {
    level[depth].push_back(start);
    if (tree[start][0] != -1)  DFS(tree[start][0], depth + 1);
    col[start]=++width;
    if(tree[start][1]!=-1)  DFS(tree[start][1], depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    col.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back(b);
        tree[a].push_back(c);
        if(a!=-1)col[a]++;
        if(b!=-1)col[b]++;
        if(c!=-1)col[c]++;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) {
            root = i;
            break;
        }
    }

    col.assign(n + 1, 0);

    DFS(root, 1);

    int maxW = 0, maxD = 0;
    for (int i = 1; level[i].size() != 0; i++) {
        int minL = level[i][0], maxL = level[i][level[i].size()-1];
        int sum = col[maxL] - col[minL] + 1;
        if (maxW < sum) {
            maxW = sum;
            maxD = i;
        }
    }
    cout << maxD << " " << maxW;

    return 0;
}
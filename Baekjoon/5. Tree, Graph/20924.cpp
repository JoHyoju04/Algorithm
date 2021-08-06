#include <iostream>
#include <vector>
using namespace std;

int n, r;
long long colLen, leafLen;
vector<bool> visited;
vector<pair<int, int> > tree[200001];
bool flag = false;

void dfs(int start, int len) {
    visited[start] = 1;
    for (int i = 0; i < tree[start].size(); i++) {
        if (!flag && (tree[start].size() >= 3||(start==r&&tree[start].size()>=2))) {
            flag = true;
            colLen = len;
        }
        if (!visited[tree[start][i].first])  dfs(tree[start][i].first, len + tree[start][i].second);
    }
    leafLen = leafLen > len ? leafLen : len;
    if (!flag) {
        flag = true;
        colLen = len;
    }
    return;
}
int main()
{
    cin >> n>>r;
    visited.assign(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }
    dfs(r, 0);
    cout << colLen << " " << leafLen - colLen;
    return 0;
}
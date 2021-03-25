#include <iostream>
#include<vector>
using namespace std;
vector<int> parent;
int find(int a) {
    if (parent[a] < 0) return a;
    else {
        int y = find(parent[a]);
        parent[a] = y;
        return y;
    }
}
bool isSameParent(int a, int b) {
    int x = find(a);
    int y = find(b);
    if (x == y)    return true;
    else return false;
}
void uni(int a, int b) {
    if (isSameParent(a, b))  return;
    int x = find(a);
    int y = find(b);
    if (parent[x] < parent[y]) {
        parent[x] += parent[y];
        parent[y] = x;
    }
    else {
        parent[y] += parent[x];
        parent[x] = y;
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, oper, a, b;
    cin >> n >> m;
    parent.assign(n + 1, -1);
    for (int i = 0; i < m; i++) {
        cin >> oper >> a >> b;
        if (oper == 0) uni(a, b);
        else {
            if (isSameParent(a, b))   cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
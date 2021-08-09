#include <iostream>
#include <vector>
using namespace std;

vector<int> tree[100001];
int n, q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, k;
        cin >> t >> k;
        if (t == 1) {
            if (tree[k].size() == 1)   cout << "no";
            else cout << "yes";
        }
        else cout << "yes";
        cout << "\n";
    }
    return 0;
}
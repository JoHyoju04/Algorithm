#include <iostream>
#include <vector>
using namespace std;
int T, N;
vector<int> ansc;

int main() {
    cin >> T;
    while (T--) {
        int parent[10001] = { 0, };
        cin >> N;
        for (int i = 0; i < N - 1; i++) {
            int root, child;
            cin >> root >> child;
            parent[child] = root;
        }
        int node1, node2;
        cin >> node1 >> node2;
        ansc.push_back(node1);
        while (parent[node1] != 0) {
            ansc.push_back(parent[node1]);
            node1 = parent[node1];
        }
        while (true) {
            if (find(ansc.begin(), ansc.end(), node2) != ansc.end()) {
                cout << node2 << "\n";
                break;
            }
            node2 = parent[node2];
        }
        ansc.clear();
    }
    return 0;
}
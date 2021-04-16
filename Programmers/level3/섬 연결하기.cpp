#include <string>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> parent;
int find(int x) {
    if (x == parent[x])    return x;
    return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)    return;
    parent[x] = y;
}
bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    parent.assign(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < costs.size(); i++) {
        if (find(costs[i][0]) != find(costs[i][1])) {
            merge(costs[i][0], costs[i][1]);
            answer += costs[i][2];
        }
    }
    return answer;
}
#include<iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct tunnel {
    int a, b;
    long long cost;
};

bool cmp(tunnel a, tunnel b) {
    return a.cost < b.cost;
}
int getParent(int a, vector<int>& parent) {
    if (parent[a] == a)    return a;
    return parent[a] = getParent(parent[a], parent);
}
bool find(int a, int b, vector<int>& parent) {
    a = getParent(a, parent);
    b = getParent(b, parent);
    if (a == b)    return true;
    return false;
}

void unionParent(int a, int b, vector<int>& parent) {

    a = getParent(a, parent);
    b = getParent(b, parent);
    parent[a] = b;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        double E;
        long long answer = 0;
        cin >> N;
        vector<pair<int, int> > edge(N);
        vector<tunnel> cost;
        vector<int> parent(N + 1, 0);
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            edge[i].first = x;
        }
        for (int i = 0; i < N; i++) {
            int y;
            cin >> y;
            edge[i].second = y;
        }
        cin >> E;
        for (int i = 0; i < N - 1; i++) {
            long long x = edge[i].first;
            long long y = edge[i].second;
            for (int j = i + 1; j < N; j++) {
                long long nx = edge[j].first;
                long long ny = edge[j].second;
                long long c = (x - nx) * (x - nx) + (y - ny) * (y - ny);
                cost.push_back({ i + 1,j + 1,c });
            }
        }
        sort(cost.begin(), cost.end(), cmp);
        for (int i = 1; i <= N; i++)   parent[i] = i;
        for (int i = 0; i < cost.size(); i++) {
            if (!find(cost[i].a, cost[i].b, parent)) {
                answer += cost[i].cost;
                unionParent(cost[i].a, cost[i].b, parent);
            }
        }
        cost.clear();
        answer = floor(answer * E + 0.5);
        cout << "#" << test_case << " " << answer << "\n";


    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int N, M, h_size = 0, c_size = 0, answer = 5000;
vector<vector<int> > house(101, vector<int>(3, 0));
vector<vector<int> > chicken(14, vector<int>(3, 0));
vector<vector<int> > chicken_list(14, vector<int>(3, 0));

int sum(vector<vector<int> > list) {
    int ret = 0, add = 0, min;
    for (int i = 0; i < h_size; i++) {
        min = 100;
        for (int j = 0; j < M; j++) {
            add = abs(house[i][0] - list[j][0]) + abs(house[i][1] - list[j][1]);
            min = min < add ? min : add;
        }
        ret += min;
    }
    return ret;
}

void DFS(int cnt, int idx) {
    if (cnt == M) {
        int dist = sum(chicken_list);
        answer = dist > answer ? answer : dist;
    }
    else {
        for (int i = idx; i < c_size; i++) {
            chicken_list[cnt][0] = chicken[i][0];
            chicken_list[cnt][1] = chicken[i][1];
            DFS(cnt + 1, i + 1);
        }
    }
}

int main() {
    cin >> N >> M;
    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            if (num == 1) {
                house[h_size][0] = i;
                house[h_size++][1] = j;
            }
            else if (num == 2) {
                chicken[c_size][0] = i;
                chicken[c_size++][1] = j;
            }
        }
    }
    DFS(0, 0);
    cout << answer;
    return 0;
}
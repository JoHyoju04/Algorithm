#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<vector<int> > map;
int nums[25 * 25];
int conn[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N, sum = 0;
void DFS(int r, int c) {
    map[r][c] = 0;
    nums[sum]++;
    for (int i = 0; i < 4; i++) {
        int r_loc = r + conn[i][0];
        int c_loc = c + conn[i][1];
        if (r_loc >= 0 && r_loc < N && c_loc >= 0 && c_loc < N) {
            if (map[r_loc][c_loc]) {
                DFS(r_loc, c_loc);
            }
        }
    }
}

int main() {
    cin >> N;
    map.assign(N, vector<int>(N, 0));
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        for (int j = 0; j < N; j++) {
            map[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j]) {
                DFS(i, j);
                sum++;
            }
        }
    }
    sort(nums, nums + sum, greater<>());
    cout << sum << "\n";
    for (int a = sum - 1; a >= 0; a--)
        cout << nums[a] << "\n";
    return 0;
}
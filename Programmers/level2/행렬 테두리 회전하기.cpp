#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> answer;
void rotate(int x1, int y1, int x2, int y2, vector<vector<int> >& m, int r, int c) {
    vector<int> nums;
    int tmp = m[x1 - 1][y1 - 1];
    nums.push_back(tmp);
    for (int i = x1 - 1; i < x2 - 1; i++) {
        nums.push_back(m[i + 1][y1 - 1]);
        m[i][y1 - 1] = m[i + 1][y1 - 1];
    }
    for (int i = y1 - 1; i < y2 - 1; i++) {
        nums.push_back(m[x2 - 1][i + 1]);
        m[x2 - 1][i] = m[x2 - 1][i + 1];
    }
    for (int i = x2 - 1; i > x1 - 1; i--) {
        nums.push_back(m[i - 1][y2 - 1]);
        m[i][y2 - 1] = m[i - 1][y2 - 1];
    }
    for (int i = y2 - 1; i > y1; i--) {
        nums.push_back(m[x1 - 1][i - 1]);
        m[x1 - 1][i] = m[x1 - 1][i - 1];
    }
    m[x1 - 1][y1] = tmp;
    answer.push_back(*min_element(nums.begin(), nums.end()));
    return;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int n = 1;
    vector<vector<int> > map(rows, vector<int>(columns, 0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = n++;
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3], map, rows, columns);
    }
    return answer;
}
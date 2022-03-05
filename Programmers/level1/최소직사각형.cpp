#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;

    int w = 0, h = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        w = max(w, min(sizes[i][0], sizes[i][1]));
        h = max(h, max(sizes[i][0], sizes[i][1]));
    }
    answer = w * h;

    return answer;
}
/*
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmpC(vector<int> a, vector<int> b) {
    return a[0] > b[0];
}
bool cmpR(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}
int solution(vector<vector<int>> sizes) {
    int answer = 0, maxNum, idx;
    sort(sizes.begin(), sizes.end(), cmpC);
    vector<vector<int> > sizesS = sizes;

    sort(sizes.begin(), sizes.end(), cmpR);

    if (sizesS[0][0] > sizes[0][1]) {
        maxNum = sizesS[0][0];
        idx = 1;
    }
    else {
        maxNum = sizes[0][1];
        idx = 0;
        sizes = sizesS;
    }

    for (int i = 0; i < sizes.size(); i++) {
        int num = sizes[i][idx];
        if (sizes[i][idx] > sizes[i][(idx + 1) % 2]) {
            num = sizes[i][(idx + 1) % 2];
        }
        answer = answer > num ? answer : num;
    }
    answer *= maxNum;
    return answer;
}
*/
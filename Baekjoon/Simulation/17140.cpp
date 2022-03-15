#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int A[102][102];
int cnt[102];
int tmp[102][102];

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)  return a.first < b.first;
    return a.second < b.second;
}

void cal(int& i, int& j, char c) {

    vector<pair<int, int> > list;

    int maxN = 0;

    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            tmp[a][b] = 0;
        }
    }

    for (int a = 1; a <= i; a++) {

        for (int idx = 1; idx <= 100; idx++) {
            cnt[idx] = 0;
        }

        list.clear();

        for (int b = 1; b <= j; b++) {
            if (c == 'R')
                cnt[A[a][b]]++;
            else cnt[A[b][a]]++;
        }

        for (int x = 1; x <= 100; x++) {
            if (cnt[x] > 0)    list.push_back({ x,cnt[x] });
        }

        sort(list.begin(), list.end(), cmp);

        for (int x = 1; x <= list.size() && x <= 50; x++) {
            if (c == 'R') {
                tmp[a][x * 2 - 1] = list[x - 1].first;
                tmp[a][x * 2] = list[x - 1].second;
            }
            else {
                tmp[x * 2 - 1][a] = list[x - 1].first;
                tmp[x * 2][a] = list[x - 1].second;
            }

        }

        maxN = maxN > list.size() ? maxN : list.size();
    }

    j = maxN * 2;

    if (c == 'R') {
        for (int a = 1; a <= i; a++) {
            for (int b = 1; b <= j; b++) {
                A[a][b] = tmp[a][b];
            }
        }
    }
    else {
        for (int a = 1; a <= j; a++) {
            for (int b = 1; b <= i; b++) {
                A[a][b] = tmp[a][b];
            }
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int time = 0, answer = -1, r, c, k;
    int cr = 3, cc = 3;

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> A[i][j];
        }
    }

    if (cr >= r && cc >= c && A[r][c] == k) {
        cout << "0";
        return 0;
    }

    while (time <= 100) {
        if (cr >= r && cc >= c && A[r][c] == k) {
            answer = time;
            break;
        }

        if (cr >= cc)  cal(cr, cc, 'R');
        else cal(cc, cr, 'C');

        time++;
    }
    cout << answer;
    return 0;
}
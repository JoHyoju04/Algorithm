#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 101

int N, M;
vector<pair<int, int> > chickenList, homeList;
int answer = 987654321;

void minChicken(const vector < pair<int, int> >& chickenM) {
    int chickenDist = 0;
    for (int i = 0; i < homeList.size(); i++) {
        int r = homeList[i].first;
        int c = homeList[i].second;
        int dist = MAX;
        for (int j = 0; j < chickenM.size(); j++) {
            int cr = chickenM[j].first;
            int cc = chickenM[j].second;
            dist = dist < abs(r - cr) + abs(c - cc) ? dist : abs(r - cr) + abs(c - cc);
        }
        chickenDist += dist;
    }
    answer = answer < chickenDist ? answer : chickenDist;
}

void selectChicken(vector<pair<int, int> > chickenM, int cnt, int idx) {
    if (cnt == M) {
        minChicken(chickenM);
        return;
    }
    for (int i = idx; i < chickenList.size(); i++) {
        chickenM.push_back({ chickenList[i].first,chickenList[i].second });
        selectChicken(chickenM, cnt + 1, i + 1);
        chickenM.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = 0;
            cin >> num;
            if (num == 1)    homeList.push_back({ i + 1,j + 1 });
            else if (num == 2)    chickenList.push_back({ i + 1,j + 1 });
        }
    }

    vector<pair<int, int> > list;
    selectChicken(list, 0, 0);

    cout << answer;

    return 0;
}
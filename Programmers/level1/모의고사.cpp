#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else    return b.first < a.first;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> students = { {1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5} };
    int score = 0;
    vector<pair<int, int> > list;
    for (int i = 0; i < 3; i++) {
        vector<int> std = students[i];
        int score = 0;
        for (int j = 0; j < answers.size(); j++) {
            if (answers[j] == std[j % std.size()])
                score++;
        }
        list.push_back({ score,i + 1 });
    }
    sort(list.begin(), list.end(), compare);
    answer.push_back(list[0].second);
    int max = list[0].first;
    for (int i = 1; i < 3; i++) {
        if (max == list[i].first)  answer.push_back(list[i].second);
    }
    return answer;
}
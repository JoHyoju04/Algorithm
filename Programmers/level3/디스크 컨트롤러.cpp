#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, j = 0, time = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (j < jobs.size() || !pq.empty()) {
        if (jobs.size() > j&& time >= jobs[j][0]) {
            pq.push(jobs[j++]);
            continue;
        }
        if (!pq.empty()) {
            time += pq.top()[1];
            answer += time - pq.top()[0];
            pq.pop();
        }
        else
            time = jobs[j][0];
    }
    return answer / jobs.size();
}
/*
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; // 현재까지 작업이 진행된 시간
    int time = 0; // 각각의 작업이 진행되는데 걸린 시간들의 합
    int size = jobs.size();

    sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0] <= start) {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if(i == jobs.size()-1) start++;
        }
    }

    answer = time / size;
    return answer;
}
*/
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    long long total_time = 0;
    int len = food_times.size();
    priority_queue <pair<int, int>> pq;
    for(int i=0; i<len; i++){
        pq.push({ -food_times[i], i + 1 });
        total_time += food_times[i];
    }
    if(total_time <= k) return -1;
    
    long long previous = 0;
    total_time = 0;
    while( total_time + (-pq.top().first - previous) * len <= k ){
        long long now = -pq.top().first;
        pq.pop();
        total_time += (now - previous) * len;
        len--;
        previous = now;
    }
    
    vector<pair<int, int>> result;
    while(!pq.empty()){
        int food_time = -pq.top().first;
        int index = pq.top().second;
        result.push_back({food_time, index});
        pq.pop();
    }
    
    sort(result.begin(), result.end(), compare);
    return result[(k - total_time) % len].second;
}
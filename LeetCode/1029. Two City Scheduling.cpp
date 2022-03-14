bool cmp(vector<int> a, vector<int> b) {
    return a[0] - a[1] < b[0] - b[1];
}
class Solution {

public:

    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int answer = 0;
        for (int i = 0; i < costs.size() / 2; i++) {
            answer += (costs[i][0] + costs[i + costs.size() / 2][1]);
        }

        return answer;
    }
};
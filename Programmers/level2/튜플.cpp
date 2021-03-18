#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > set;
    vector<int> nums;
    int cnt = 0;
    int idx[501] = { 0, };
    int maxSize = 0;
    string str;
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] != '{' && s[i] != ',' && s[i] != '}') {
            str += s[i];
        }
        else if (str.size() != 0 && (s[i] == ',' || s[i] == '}')) {
            nums.push_back(stoi(str));
            str = "";
            if (s[i] == '}') {
                idx[nums.size()] = cnt++;
                set.push_back(nums);
                maxSize = maxSize > nums.size() ? maxSize : nums.size();
                nums.clear();
            }
        }
    }
    for (int i = 1; i <= maxSize; i++) {
        vector<int> vec = set[idx[i]];
        for (int j = 0; j < vec.size(); j++) {

            if (find(answer.begin(), answer.end(), vec[j]) == answer.end())
                answer.push_back(vec[j]);

        }
    }
    return answer;
}
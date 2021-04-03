#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string s1, string s2) {
    if (s1.size() == s2.size())    return s1 > s2;
    else return s1 + s2 > s2 + s1;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sorted;
    if (*max_element(numbers.begin(), numbers.end()) == 0)  return "0";
    for (int i = 0; i < numbers.size(); i++)
        sorted.push_back(to_string(numbers[i]));
    sort(sorted.begin(), sorted.end(), compare);
    for (int i = 0; i < sorted.size(); i++)
        answer += sorted[i];
    return answer;
}
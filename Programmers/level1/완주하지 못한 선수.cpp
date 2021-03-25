#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

//sort 사용
string solutionSort(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++)
        if (participant[i] != completion[i])   return participant[i];
    return participant.back();
}

//해시 사용
string solutionHash(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> participants;
    for (string name : participant)
        ++participants[name];
    for (string name : completion)
        --participants[name];
    for (auto pair : participants) {
        if (pair.second > 0)   return pair.first;
    }
}
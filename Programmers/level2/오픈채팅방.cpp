#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<pair<string, string> > newRecord;
    for (int i = 0; i < record.size(); i++) {
        string s1, uid, name;
        stringstream ss;
        ss.str(record[i]);
        ss >> s1; ss >> uid;
        if (s1 == "Leave") {
            newRecord.push_back({ uid,"´ÔÀÌ ³ª°¬½À´Ï´Ù." });
            continue;
        }
        else if (s1 == "Enter") {
            newRecord.push_back({ uid,"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù." });
        }
        ss >> name;
        m[uid] = name;

    }
    for (int i = 0; i < newRecord.size(); i++)
        answer.push_back(m[newRecord[i].first] + newRecord[i].second);
    return answer;
}
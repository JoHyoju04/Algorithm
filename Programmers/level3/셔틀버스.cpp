#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crew;
    for (int i = 0; i < timetable.size(); i++)
    {
        string ts=timetable[i];
        int hour=stoi(ts.substr(0,2));
        int mini=stoi(ts.substr(3,2));
        crew.push_back(hour*60+mini);

    }
    sort(crew.begin(), crew.end());
 
    int shuttleTime = 540;
    int crewIdx = 0;
    int answerTime;
    for (int i = 1; i <= n; i++, shuttleTime = shuttleTime + t)
    {
        int cnt = 0;
        for (int j = crewIdx; j < crew.size(); j++)
        {
            if (crew[j] <= shuttleTime)
            {
                crewIdx++;
                cnt++;
                if (cnt == m) break;
            }
        }
 
        if (i == n)
        {
            if (cnt == m) answerTime = crew[crewIdx - 1] - 1;
            else answerTime = shuttleTime;
        }
    }
    string hour=to_string(answerTime/60);
    string mini=to_string(answerTime%60);
    if(hour.size()!=2)  hour.insert(0,"0");
    if(mini.size()!=2)  mini.insert(0,"0");
    string answer=hour+":"+mini;
    return answer;
}
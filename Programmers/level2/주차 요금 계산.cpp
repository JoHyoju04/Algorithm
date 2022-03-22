#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

int hourToMin(string t) {
    int ret = stoi(t.substr(0, 2)) * 60;
    ret += stoi(t.substr(3));
    return ret;
}

int calPrice(int t, vector<int> fees) {
    int ret = fees[1];    //기본 요금
    if (t <= fees[0])  return ret;
    int share = (t - fees[0]) / fees[2];
    if ((t - fees[0]) % fees[2] != 0) share = share + 1;
    ret += share * fees[3];
    return ret;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, int> in;
    map<string, int> carTime;

    for (int i = 0; i < records.size(); i++) {
        string str = records[i];
        string t = str.substr(0, 5);
        string num = str.substr(6, 4);
        string state = str.substr(11);

        int time = hourToMin(t);

        if (state == "IN") in[num] = time;
        else {
            int sumTime = time - in[num];
            carTime[num] = carTime[num] + sumTime;
            in.erase(num);
        }
    }

    for (auto it = in.begin(); it != in.end(); it++) {
        int sumTime = 1439 - (it->second);
        carTime[it->first] = carTime[it->first] + sumTime;
    }
    for (auto it = carTime.begin(); it != carTime.end(); it++) {
        int time = calPrice(it->second, fees);
        answer.push_back(time);
    }
    return answer;
}
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cnt[360000];//00:00:00 ~ 99:59:59를 초로 계산하면 0~359999

int strToInt(string str) {
    string h = str.substr(0, 2);
    string m = str.substr(3, 2);
    string s = str.substr(6, 2);
    int ret = stoi(h) * 3600 + stoi(m) * 60 + stoi(s);
    return ret;
}

string intToStr(int n) {
    string s = to_string(n % 60);
    string m = to_string(n % 3600 / 60);
    string h = to_string(n / 3600);
    if (s.size() == 1)    s = "0" + s;
    if (m.size() == 1)    m = "0" + m;
    if (h.size() == 1) h = "0" + h;
    string ret = h + ":" + m + ":" + s;
    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for (int i = 0; i < logs.size(); i++) { //각 재생시간에 해당하는 구간에 +1
        int start = strToInt(logs[i].substr(0, 8));
        int end = strToInt(logs[i].substr(9));
        for (int j = start; j < end; j++) {
            cnt[j]++;
        }
    }
    int playtime = strToInt(play_time); //총 재생시간
    int advtime = strToInt(adv_time); //광고시간

    queue<int> q; //가장 첫 원소를 빼고 뒤에 삽입하기 때문에 큐사용
    int index = 0; //결정된 광고 시작시간
    long long tmp = 0;
    long long result = 0; //최대 구간합

    for (int i = 0; i < advtime; i++) {//0초부터 시작했을때 구간합
        tmp += cnt[i];
        q.push(cnt[i]);
    }

    result = tmp;
    for (int i = advtime; i < playtime; i++) { //투 포인터 알고리즘 
        tmp -= q.front();
        q.pop();
        tmp += cnt[i];
        q.push(cnt[i]);
        if (result < tmp) {//구간합이 최대일때
            result = tmp;
            index = i - advtime + 1;//현재 광고 시작시간
        }
    }
    answer = intToStr(index);

    return answer;
}
/*
#include <string>
#include <vector>
#include <queue>
using namespace std;

int ad[360000];

int strToSec(string s){
    int ret=0;

    string h = s.substr(0,2);
    string m = s.substr(3,2);
    string c = s.substr(6,2);

    ret+=stoi(h)*60*60;
    ret+=stoi(m)*60;
    ret+=stoi(c);
    return ret;
}

string secToStr(int n){
    string ret="";

     int s = n%60; n/=60;
    int m = n%60; n/=60;
    int h = n;

    if(h<10) ret+="0";
    ret+=to_string(h);
    ret+=":";

    if(m<10) ret+="0";
    ret+=to_string(m);
    ret+=":";

    if(s<10) ret+="0";
    ret+=to_string(s);

    return ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    for(string s:logs){
        int start = strToSec(s.substr(0,8));
        int finish = strToSec(s.substr(9,8));
        for(int i=start;i<finish;i++) ad[i]++;
    }

    int N = strToSec(play_time);
    int len = strToSec(adv_time);

    int idx=0;
    long long sum=0;
    long long maxSum=0;

    int left=0,right=len-1;

    for(int i=0;i<len;i++){
        sum+=ad[i];
    }
    maxSum=sum;

    while(right<N-1){
        sum-=ad[left++];
        sum+=ad[++right];
        if(sum > maxSum){
            idx = right-len+1;
            maxSum = sum;
        }
    }

    answer = secToStr(idx);
    return answer;
}
*/
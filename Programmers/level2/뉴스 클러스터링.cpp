#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

void makeSet(string str, unordered_map <string, int>& m) {
    for (int i = 0; i < str.size() - 1; i++) {
        if (isalpha(str[i]) && isalpha(str[i + 1])) {
            string s = str.substr(i, 2);
            m[s]++;
        }
    }
}
int solution(string str1, string str2) {
    int answer = 65536;
    unordered_map<string, int> m1, m2;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    makeSet(str1, m1);
    makeSet(str2, m2);

    if (m1.size() == 0 && m2.size() == 0)    return answer;
    int interN = 0;
    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        if (m2.find(iter->first) != m2.end())
            interN += min(m1[iter->first], m2[iter->first]);
    }

    int unionN = 0;
    for (auto iter = m2.begin(); iter != m2.end(); iter++) {
        if (m1.find(iter->first) != m1.end())
            m1[iter->first] = max(m1[iter->first], m2[iter->first]);
        else m1[iter->first] = iter->second;
    }

    for (auto iter = m1.begin(); iter != m1.end(); iter++) {
        unionN += (iter->second);
    }

    answer = (double)interN / (double)unionN * 65536;
    return answer;
}
/*
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

void mapping(string str,vector<string> &vec){
    for(int i=0;i<str.size()-1;i++){
        if(!isalpha(str[i]) || !isalpha(str[i+1]))    continue;
        string s;
        s.push_back(tolower(str[i]));
        s.push_back(tolower(str[i+1]));
        vec.push_back(s);
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1,s2;
    map<string,int> m1,m2;
    double inter=0,uni=0;
    
    mapping(str1,s1);
    mapping(str2,s2);
    
    if(s1.size()==0 && s2.size()==0)    return 65536;
    
    for(int i=0;i<s1.size();i++)    m1[s1[i]]++;
    for(int i=0;i<s2.size();i++)    m2[s2[i]]++;
    
    for(auto iter=m1.begin();iter!=m1.end();iter++){
        string s=iter->first;
        if(m2[s]==0)    continue;
        inter+=min(m1[s],m2[s]);
    }
    uni=s1.size()+s2.size()-inter;
    answer=(inter/uni)*65536;
    return answer;
}
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> m;
    char ch='A';
    string str="";
    for(int i=1;i<=26;i++){
        str=ch;
        m.insert({str,i});
        ch+=1;
    }
    
    int idx=27;
    str="";
    for(int i=0;i<msg.size();i++){
        string s="";
        s=msg[i];
        str+=s;
        if(m[str]==0){
            str.pop_back();
            answer.push_back(m[str]);
            if(i!=msg.size()-1)
                m[str+s]=idx++;
            str.clear();
            i--;
        }
        if(i==msg.size()-1)   answer.push_back(m[str]);
    }
    return answer;
}
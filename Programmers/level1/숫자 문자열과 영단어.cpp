#include <string>
#include <vector>

using namespace std;
int mapping(string str){
    if(str=="zero")
        return 0;
    else if(str=="one")
        return 1;
    else if(str=="two")
        return 2;
    else if(str=="three")
        return 3;
    else if(str=="four")
        return 4;
    else if(str=="five")
        return 5;
    else if(str=="six")
        return 6;
    else if(str=="seven")
        return 7;
    else if(str=="eight")
        return 8;
    else if(str=="nine")
        return 9;
    return -1;
}
int solution(string s) {
    int answer = 0;
    string answerS,st;
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i]))  st+=s[i];
        else answerS+=s[i];
        if(st.size()>=3){
            int ret=mapping(st);
            if(ret!=-1){
                answerS+=to_string(ret);
                st="";
            }
        }
    }
    answer=stoi(answerS);
    return answer;
}
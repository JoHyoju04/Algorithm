#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int calculate(map<string,int> jb,map<string,int> lk){
    int ret=0;
    for(auto iter=lk.begin();iter!=lk.end();iter++){
        string lang=iter->first;
        ret+=(jb[lang]*lk[lang]);
    }
    return ret;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    string answer = "";
    map<string,int> like;
    int maxNum=0;
    for(int i=0;i<languages.size();i++)
        like.insert({languages[i],preference[i]});
    
    sort(table.begin(),table.end());
    for(int i=0;i<5;i++){
        map<string,int> job;
        string jName,str;
        int sIdx=0,fIdx;
        for(int j=6;j>0;j--){
            fIdx=table[i].find(" ",sIdx);
            if(fIdx==-1)    str=table[i].substr(sIdx);
            else    str=table[i].substr(sIdx,fIdx-sIdx);
            sIdx=fIdx+1;
            if(j==6)    jName=str;
            else{
                job[str]=j;
            }
        }
        int num=calculate(job,like);
        if(maxNum<num){
            maxNum=num;
            answer=jName;
        }
    }
    return answer;
}
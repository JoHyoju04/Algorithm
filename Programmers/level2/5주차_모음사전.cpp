#include <string>
#include <vector>
#include <map>
using namespace std;
string alpha="AEIOU";
string str;
int len;
map<string,int> m;

void dfs(int cnt){
    if(cnt==5)  return;
    for(int i=0;i<5;i++){
        str+=alpha[i];
        len++;
        m.insert({str,len});
        dfs(cnt+1);
        str.pop_back();
    }
}
int solution(string word) {
    int answer = 0;
    dfs(0);
    answer=m.find(word)->second;
    return answer;
}
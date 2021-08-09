#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    map<string,int> m;
    string before;
    
    for(int i=0;i<words.size();i++){
        m[words[i]]++;
        if(i==0){
            before=words[0];
            continue;
        }
        if(m[words[i]]==2||words[i][0]!=before.back()){
            answer[0]=(i%n)+1;
            answer[1]=i/n+1;
            break;
        }
        before=words[i];
    }

    return answer;
}
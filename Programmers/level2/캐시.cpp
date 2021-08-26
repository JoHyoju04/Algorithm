#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string,int> m;
    for(int i=0;i<cities.size();i++){
        string city=cities[i];
        transform(city.begin(),city.end(),city.begin(),::tolower);
        auto it=m.find(city);
        if(cacheSize==0)    answer+=5;
        else if(it==m.end()){
            if(m.size()==cacheSize){
                string key="";
                int min=cities.size();
                for(auto j=m.begin();j!=m.end();j++){
                    if(min>j->second){
                        min=j->second;
                        key=j->first;
                    }
                }
                m.erase(key);
            }
            answer+=5;
        }
        else answer+=1;
        
        m[city]=i;
    }
    return answer;
}
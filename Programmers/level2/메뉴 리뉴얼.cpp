#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<string, int> m;
void dfs(int cnt, int idx, string str, string order) {
    if (cnt != 0 && cnt != 1)  m[str]++;
    if (cnt == order.size())   return;
    for (int i = idx; i < order.size(); i++) {
        str += order[i];
        dfs(cnt + 1, i + 1, str, order);
        str.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        string str = orders[i];
        sort(str.begin(), str.end());
        dfs(0, 0, "", str);
    }

    for (int i = 0; i < course.size(); i++) {
        int size = course[i];
        int mCnt = 2;
        vector<string> list;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second >= mCnt && (it->first).size() == size) {
                if (it->second > mCnt) {
                    mCnt = it->second;
                    list.clear();
                }
                list.push_back(it->first);
            }
        }
        for (int j = 0; j < list.size(); j++)  answer.push_back(list[j]);
    }

    sort(answer.begin(), answer.end());
    return answer;
}
/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> m;
bool compare(pair<int,string> a,pair<int,string> b){
    if(a.second.size()==b.second.size())    return a.first>b.first;
    else    return (a.second).size()<(b.second).size();
}
void dfs(int idx,int minSize,string tmp,string str){
    if(tmp.size()>=minSize){
        string tmp_=tmp;
        sort(tmp.begin(),tmp.end());
        m[tmp]++;
        tmp=tmp_;
    }
    for(int i=idx;i<str.size();i++){
        tmp+=str[i];
        dfs(i+1,minSize,tmp,str);
        tmp.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++)
        dfs(0,course[0],"",orders[i]);
    
    vector<pair<int,string> > vec;
    for(auto iter=m.begin();iter!=m.end();iter++){
        if(iter->second>=2){
            bool flag=false;
            for(int i=0;i<course.size();i++){
                if(course[i]==(iter->first).size()){
                    flag=true;
                    break;
                }
            }
            if(flag)    vec.push_back({iter->second,iter->first});
        }
    }
    sort(vec.begin(),vec.end(),compare);
    int cnt=vec[0].first;
    for(int i=0;i<vec.size();i++){
        if(i==0)    answer.push_back(vec[i].second);
        else{
            if(answer[answer.size()-1].size()==vec[i].second.size()&&cnt==vec[i].first)  answer.push_back(vec[i].second);
            if(answer[answer.size()-1].size()<vec[i].second.size()){
                answer.push_back(vec[i].second);
                cnt=vec[i].first;
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
*/
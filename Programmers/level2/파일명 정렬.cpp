#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct File{
    string head;
    int number,idx;
};

struct compare{
    bool operator()(File &a,File &b){
        if(a.head!=b.head)  return a.head>b.head;
        else if(a.number!=b.number) return a.number>b.number;
        else return a.idx>b.idx;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    priority_queue<File,vector<File>,compare> pq;
    for(int i=0;i<files.size();i++){
        string head="";
        string num="";
        string str=files[i];
        for(int j=0;j<str.size();j++){
            if(head.size()!=0&&num.size()!=0&&!isdigit(str[j])) break;
            else if(isdigit(str[j]))    num+=str[j];
            else head+=str[j];
        }
        transform(head.begin(),head.end(),head.begin(),::tolower);
        pq.push({head,stoi(num),i});
    }
    
    while(!pq.empty()){
        int index=pq.top().idx;
        pq.pop();
        answer.push_back(files[index]);
    }
    return answer;
}
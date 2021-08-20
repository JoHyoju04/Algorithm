#include <string>
#include <vector>
#include <map>
using namespace std;

map<long long,long long> room;

long long find(long long n){
    if(room[n]==0) return n;
    return room[n]=find(room[n]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        long long n=room_number[i];
        if(room[n]==0){
            answer.push_back(n);
            room[n]=find(n+1);
        }
        else{
            long long next=find(n);
            answer.push_back(next);
            room[next]=find(next+1);
        }
    }
    return answer;
}